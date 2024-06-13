#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/err.h>
#include<linux/fs.h>

#define DEVICE_NAME "char_dev"

dev_t dev = 0;

static struct class *dev_class;
static int __init chardev_init(void)
{
	if(alloc_chrdev_region(&dev,0,1,DEVICE_NAME)<0)
	{
		pr_info("Memory allocation failed\n");
		return -ENOMEM;
	}
	dev_class = class_create(THIS_MODULE,DEVICE_NAME);
	if(IS_ERR(dev_class))
	{
		pr_err("Failed to create device''\n");
		class_destroy(dev_class);
		unregister_chrdev_region(dev,1);
		return PTR_ERR(dev_class);
	}

	if(IS_ERR(device_create(dev_class,NULL,dev,NULL,DEVICE_NAME)))
	{
		pr_err("Failed to create device..\n");
		device_destroy(dev_class,dev);
		unregister_chrdev_region(dev,1);
		return -EFAULT;
	}
	pr_info("MEmoery allocated successfully..\n");
	return 0;
}
static void __exit chardev_exit()
{
	class_destroy(dev_class);
	device_destroy(dev_class,dev);
	unregister_chrdev_region(dev,1);
}

module_init(chardev_init);
module_init(chardev_exit);
