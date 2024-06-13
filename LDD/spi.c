#include<linux/init.h>
#include<linux/modules.h>
#include<linux/kernel.h>
#include<linux/spi/spi.h>
#include<linux/cdev.h>
#include<linux/fs.h>

#define DRIVER_NAME "spi_driver"
#define DEVICE_NAME "spi_device"

static struct cdev cdev;
static struct spi_device *ex_spi_device;
static dev_t dev;
sttaic struct class *ex_spi_class;

static int ex_spi_transfer(struct spi_device *spi,uint8_t *txbuf,uint8_t *rxbuf,size_t len)
{
	struct spi_transfer t = {
		.tx_buf = txbuf,
		.rx_buf = rxbuf,
		.len = len,
	};
	struct spi_message m;
	spi_message_init(&m);
	spi_message_add_tail(&t,&m);
	return spi_sync(spi,&m);
}	

static struct file_operations spi_fops = 
{
	.owner  = THIS_MODULE,
	.read  = spi_read,
	.open = spi_open,
	.write = spi_write,
};
static int spi_open(struct inode *inode, struct file *file)
{
	file->private_data  = ex_spi_device ;
	return 0;
}
static size_t spi_read(struct file *file, const char __user *buf,size_t len, loff_t *off)
{
	struct spi_device *spi = file->private_data;
	uint8_t *rxbuf;
       	int ret;
	rxbuf = kzalloc(len,GFP_KERNEL);
	if(!rxbuf) return -ENOMEM;
	if(copy_to_user(rxbuf,buf,len))
	{
		kfree(rxbuf);
		return -EFAULT;
	}
	ret = ex_spi_transfer(spi,NULL,rxbuf,len);
	if(ret <0) 
	{
		kfree(rxbuf);
		return ret;
	}

	kfree(rxbuf);
	return len;

}
static size_t spi_write(struct file *file, const char __user *buf,size_t len, loff_t *off)
{
	struct spi_device *spi = file->private_data;
	uint8_t *txbuf;
	int ret;

	txbuf = kzalloc(len,GFP_KERNEL);

	if(!txbuf) return -ENOMEM;
	if(copy_from_user(txbuf,buf,len)) 
	{
		kfree(txbuf);
		return -EFAULT;
	}

	ret = ex_spi_transfer(spi,txbuf,NULL,len);
	kfree(txbuf);
	if(ret<0) return ret;

	return len;
}
static const struct spi_device_id example_spi_id[]  = {
	{"example_spi_device",0},
	{},
};
MODULE_DEVICE_TABLE(spi,example_spi_id);
static struct spi_driver example_spi_driver = {
	.driver = {
		.name =  DRIVER_NAME,
		.owner  = THIS_MODULE,
	},
	.id_table = spi_id,
	.probe = spi_probe,
	.remove = spi_remove,
};
static int spi_probe(struct spi_device *spi)
{
	int ret;
	pr_info("Driver name:%s\n",DRIVER_NAME);

	if(alloc_chrdev_region(&dev,0,1,DEVICE_NAME)<0)
	{
		pr_info("FAIled to alloc mem\n");
		return -1;
	}
	cdev_init(&cdev,&spi_fops);
	if(cdev_add(&cdev,dev,1)<0)
	{
		pr_err("failed to add to system\n");
		unregister_chrdev_region(dev,1);
		return -1;
	}
	ex_spi_class = class_create(THIS_MODULE,DEVICE_NAME);
	if(IS_ERR(ex_spi_class))
	{
		pr_err("faliled to create class\n");
		cdev_del(&cdev);
		unregister_chrdev_region(dev,1);
		return -1;
	}

	if(!device_create(ex_spi_class,NULL,dev,NULL,DEVICE_NAME))
	{
		pr_err("failed to create\n");
		class_destroy(ex_spi_class);
		 cdev_del(&cdev);
                unregister_chrdev_region(dev,1);
		return -ENOMEM;
	}

ex_spi_class = spi;

}
static int spi_remove(struct spi_device *spi)
{
	cdev_del(&cdev);
	class_destroy(ex_spi_class);
	unregister_chrdev_region(dev,1);
}
static int __init spi_init(void)
{
	return spi_register_driver(&example_spi_driver);
}
static void __exit spi_exit()
{
	spi_unregister_driver(&example_spi_driver);
}

module_init(spi_init);
module_exit(spi_exit);
	
