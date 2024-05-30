#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
//export variable
int var = 23;
// export function
int add(int a,int b)
{
	return a+b;
}

EXPORT_SYMBOL(var);
EXPORT_SYMBOL(add);

static int __init exp_init(void)
{
	pr_info("Module loaded..\n");
	return 0;
}
static void __exit exp_exit(void)
{
	pr_info("Module removed..\n");
}
module_init(exp_init);
module_exit(exp_exit);
