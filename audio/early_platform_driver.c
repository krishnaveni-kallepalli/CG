#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/platform_device.h>
#include<linux/early_platform_device.h>

static struct platform_device ep_dev=
{
	.id = 0;
	.name = "EP";
};
static struct platform_devices *ep_devs[] __initdata=
{
	&ep_dev,
	NULL,
};

static int __init ep_parse(void)
{
	if(!strcmp(param,"EP"))
	{
		pr_info("Device reg through Cmd line.\n");
		platform_device_register(&ep_dev);
	}
	return 0;
}
early_param("Earlyparam",ep_parse);

static int early_ex_probe(struct platform_device *pdev)
{
	pr_info("probe called for %s\n",pdev->name);
	return 0;
}

static struct platform_driver ep_drv=
{
	.driver = {
		.name = "early_example",
	},
	.probe = early_ex_probe,
};
static int __init ep_parse(void)
{
	int x;
	x=early_platform_add_devices(ep_dev,ARRAY_SIZE(ep_dev));
	if(x) pr_err("Falied to register..\n");
	x = early_platform_driver_register(&ep_drv);
	if(x) pr_err("Failed to reg..\n");
	
        return x;
}
static void __exit ep_exit()
{
	early_platform_driver_unregister(&ep_drv);
	early_platform_del_devices(ep_dev,ARRAY_SIZE(ep));
}
module_init(ep_init);
module_exit(ep_exit);
