#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/sound.h>
#include<linux/soundcard.h>
#include<uaccess.h>
#include<slab.h>


#define DEV_NAME "AUDIO"
#define CLASS_NAME "AUD"

static int majno;

static struct class* audCls = NULL;
static struct device* audDev = NULL;
static struct sund_pcm_substream* substream;

static char* audBuffer= NULL;
static size_t buffer_size =0;


static struct snd_pcm_hardware pcm_config = 
{
	.info = SNDRV_PCM_INFO_MMAP | SNDRV_PCM_INFO_MMAP_VALID,
	.format = SNDRV_PCM_FMTBIT_S16_LE,
	.rates = SNDRV_PCM_RATES_CONTINUOUS,
	.rate_min = 8000,
	.rate_max = 48000,
	.channels_min = 1,
	.channels_max = 2,
	.buffer_bytes_max = 64*1024,
	.period_bytes_min = 4*1024;
	.period_bytes_max = 16*1024;
	.periods_min = 2,
	.periods_max = 4,

};

static int dev_open(struct inode *inode, struct file *file)
{
	pr_info("Opend...\n");
	return 0;
}
static int dev_release(struct inode *inode, struct file *file)
{
	pr_info("Released...\n");
	return 0;
}
static size_t dev_write(struct file *file, const char *buffer, size_t len,loff_t *off)
{
	printk("Length:%d\n",len);
	if(len>buffer_size)
	{
		audBuffer = realloc(audBuffer,len,GFP_KERNEL);
		if(!audBuffer) 
		{
			pr_err("cannot allocate buffer..\n");
			return -ENOMEM;
		}
		buffer_size = len;
	}
	if(copy_from_user(audBuffer,buffer,len)<0)
	{
		pr_err("Failed to copy from usr..\n");
		return -EFAULT;
	}
	err = snd_pcm_lib_write(substream,audBuffer,len);
	if(err<0)
	{
		pr_err("Failed to write to buffer..\n");
		return err;
	}
	return len;
}
static struct file_operations fops = 
{
	.owner = THIS_MODULE,
	.open  = dev_open,
	.release = dev_release,
	.write = dev_write,
};

static int pcm_open(struct inode *inode,struct file *file)
{
	struct snd_pcm_substream *substream;
	int err;

	substream = kmalloc(sizeof(*substream),GFP_KERNEL)
	if(substream  == NULL)
		return -ENOMEM;
	substream->runtime = snd_pcm_alloc_stream(runtime,SNDRV_PCM_STREAM_PLAYBACK, &err);
	if(substream->runtime == NULL)
	{
		kfree(substream);
		return -ENOMEM;
	}
	file->private_data = substream;
	return 0;
}
static int pcm_release(struct inode *inode, struct file *file)
{
	struct snd_pcm_substream *substream  = file->private_data;
	snd_pcm_free_substream(substream);
	kfree(substream);
	return 0;
}

static struct file_operations pcm_fops = 
{
	.owner = THIS_MODULE,
	.open = pcm_open,
	.release = pcm_release,
	.write = pcm_write,
};
static int __init play_audio(void)
{
	pr_info("Audio driver Init..\n");
	majno = register_chrdev_region(0,DEVICE_NAME,&fops);
	if(majno < 0)
	{
		pr_info("Majno allocation failed..\n");
		return majno;
	}
	
	audCls = class_create(THIS_MODULE,CLASS_NAME);
	if(IS_ERR(audCls))
	{
		pr_err("Failed to cretae class..\n");
		goto r_class;
		return PTR_ERR(audCls);
	}
	pr_info("Class successfully created..\n");
	
	audDev = device_create(audCls,NULL,MKDEV(majno,0),NULL,DEVICE_NAME);
	if(IS_ERR(audDev))
	{
		pr_err("Failed to create device..\n");
		goto r_device;
		return PTR_ERR(audDev);
	}
	err = snd_pcm_new (THIS_MODULE,DEVICE_NAME,0,0,1,&substream);
	if(err<0)
	{
		pr_err("Failed to create PCM device ..\n");
		goto r_device;
		return err;
	}
	substream->ops.open = audio_pcm_open;
        substream->ops.release = audio_pcm_release;
        substream->ops.ioctl = snd_pcm_lib_ioctl;
        substream->ops.hw_params = snd_pcm_lib_hw_params;
        substream->ops.prepare = snd_pcm_lib_prepare;
        substream->ops.trigger = snd_pcm_lib_trigger;
        substream->ops.pointer = snd_pcm_lib_pointer;

        substream->runtime->hw = pcm_config;
        snd_pcm_set_ops(substream, SNDRV_PCM_STREAM_PLAYBACK, &pcm_fops);

	pr_info("Devcie created successfully...\n");

r_class:
	unregister_chrdev_region(majno,DEVICE_NAME);
r_device:
	class_destroy(audCls);
	unregister_chrdev_region(majno,DEVICE_NAME);
return 0;
}
static void __exit stop_audio(void)
{
    	if (substream)
        	snd_pcm_release_substream(substream);

    	if (audioDevice)
        	device_destroy(audCls, MKDEV(majno, 0));

        if (audioClass)
                class_destroy(audCls);

    	if (majorNumber)
		unregister_chrdev(majno, DEVICE_NAME);

    	if (audBuffer)
	    kfree(audBuffer);
	pr_info("Audio driver exit..\n"); 
}
module_init(play_audio);
module_exit(stop_audio);

