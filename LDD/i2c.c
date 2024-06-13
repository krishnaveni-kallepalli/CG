#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/i2c.h>		
static const struct i2c_device_id example_i2c_id[] = {
        {"example_i2c_devcie",0},
        {}
};
MODULE_DEVICE_TABLE(i2c,example_i2c_id);

static struct i2c_driver example_i2c_driver={
	.driver = {
		.name  = "example_i2c_driver",
	},
	.id_table = example_i2c_id,
	.probe = example_i2c_probe,
	.remove = example_i2c_remove,
};

static int example_i2c_probe(struct i2c_client *client,const struct i2c_device_id *id)
{
	pr_info("name:%s\n",client->name);
	return 0;
}
static int example_i2c_remove(struct i2c_client *clent)
{
	pr_info("Dev_removed:%s\n",client->name);
	pr_info("Removed Successsfully..\n");
	return 0;
}
static int __init i2c_init(void)
{
	return i2c_add_driver(&example_i2c_driver);
}
static void __exit i2c_exit()
{
	i2c_del_driver(&example_i2c_driver);
}

module_init(i2c_init);
module_exit(i2c_exit);



