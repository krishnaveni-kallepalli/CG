#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>

#define DEVICE_NAME "char_dev"

dev_t dev = 0;


static int __init chardev_init(void)
{
	if(alloc_chrdev_region(&dev,0,1,DEVICE_NAME)<0)
	{
		pr_info("Memory allocation failed\n");
		return -ENOMEM;
	}
	pr_info("MEmoery allocated successfully..\n");
	return 0;
}
static void __exit chardev_exit()
{
	unregister_chrdev_region(dev,1);
}

module_init(chardev_init);
module_init(chardev_exit);
