#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>

dev_t dev = MKDEV(244,9);
static struct class *dev_class;
static struct cdev etx_cdev;
static struct file_operations fops = 
{
	.owner = THIS_MODULE,
	.read = etx_read,
	.write = etx_write,
	.open = etx_open,
	.release = etx_release,
};

static int etx_open(struct inode *inode,struct file *fp)
{
	pr_info("Open..\n");
	return 0;
}

static int etx_release(struct inode *inode, struct file *fp)
{
	pr_info("release//\n");
	return 0;
}
static size_t etx_read(struct file *fp, char __user *buf,size_ len, loff_t *off)
{
	pr_info("Read op..\n");
	return 0;
}
static size_t etx_write(struct file *fp, const char __user *buff, size_t len, loff_t *off)
{
	pr_info("Write op..\n");
	return len;
}


static int __init hi(void)
{
	if(cllaoc_chrdev_region(&dev,0,1,"chr_dev")<0)
	{
		pr_info("Cannot alloc chrdev\n");
		return -1;
	}	
	pr_info("Maj.no %d\n minor no.%d\n",MAJOR(dev),MINOR(dev));

	cdev_init(&etx_cdev,&fops);
	if(cdev_add(&etx_cdev,dev,1)<0)
	{
		pr_info("cannot add to system\n");
		goto r_class;
	}

	dev_class = create_class(THIS_MODULE,"etx_class");
	if((dev_class))
	{
		pr_err("cannot create class \n");
		goto r_class;
	}

	if(IS_ERR(devcie_create(dev_class,NULL,dev,NULL,"etx_device")))
	{
		pr_err("cannit create devcie \n");
	       goto r_device;	
	}
r_class:
	class_destroy(dev_class);
r_device:
	unregister_chrdev_region(dev,1);
}
static void __exit he(void)
{
	device_destroy(dev_class,dev);
	class_destroy(dev_class);
	cdev_del(&etx_cdev);
	unregister_chrdev_region(dev,1);
	pr_info("Removed\n");
}
module_init(hi);
module_exit(he);


