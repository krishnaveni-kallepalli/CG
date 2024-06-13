#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

#define DEVICE_NAME "char_device"
dev_t dev = MKDEV(234,0);
static int __init mmi(void)
{
	register_chrdev_region(dev,1,DEVICE_NAME);
	pr_info("major no: %d\n",MAJOR(dev));
	pr_info("minor no: %d\n",MINOR(dev));
	pr_info("Insterted..\n");
	return 0;
}
static void __exit mme()
{
	unregister_chrdev_region(dev,1);
	pr_info("removed..\n");
}

module_init(mmi);
module_exit(mme);
