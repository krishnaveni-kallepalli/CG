#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/

static struct file_operations()




static int __int aud_init(void)
{
	pr_info("Audio processing successfull..\n");
	return 0;
}
static void __exit aud_exit(void)
{
	pr_info("Audio Module removing ..\n"); 
}
module_init(aud_init);
module_exit(aud_exit);

