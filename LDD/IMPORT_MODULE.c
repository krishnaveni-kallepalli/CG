#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");

extern int var;
extern int add(int a,int b);


static int __init imp_init(void)
{
	pr_info("Import loaded ..\n");
	pr_info("Exported Var val: %d\n",var);
	pr_info("Exported function add Result:%d\n",add(2,3));
	return 0;
}
static void __exit imp_exit(void)
{
	pr_info("Import unloaded..\n");	
}

module_init(imp_init);
module_exit(imp_exit);
