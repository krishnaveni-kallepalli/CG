#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/sound.h>
#include<linux/soundcard.h>


#define DEV_NAME "AUDIO"
#define CLASS_NAME "AUD"

static int majno;

static struct class* audCls = NULL;
static struct device* audDev = NULL;

static char* audBuffer= NULL;
static size_t buffer_size =0;


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
		buffer_size = len;
	}
	copy_from_user(audBuffer,buffer,len);
	return len;
}
static struct file_operations fops = 
{
	.open  = dev_open,
	.release = dev_release,
	.write = dev_write,
}

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
	device_destroy(audCls,MKDEV(majno,0));
	class_unregister(audCls);

	class_destroy(audCls);
        unregister_chrdev_region(majno,DEVICE_NAME);
	if(audBuffer)
		kfree(audBuffer);
	pr_info("Audio driver exit..\n"); 
}
module_init(play_audio);
module_exit(stop_audio);

