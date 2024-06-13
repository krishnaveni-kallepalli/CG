#include<linux.init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/kdev_t	.h>
#include<linux/types.h>

#define DEVICE_NAME "char_device"

dev_t dev = 0;

static int __init mmi(void)
{
	alloc_chrdev_region(&dev,0,1,DEVICE_NAME);
	pr_info("%d %d",MAJOR(dev),MINOR(dev));
	return 0;
}
static void __exit mme()
{
	unregister_chrdev_region(dev,1);
}
module_init(mmi);
module_exit(mme);

