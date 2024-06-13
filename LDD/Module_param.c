#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");
int value;
int a[10];
char *ptr;
int cb_val=0;
module_param(val,int,S_IRUSR|S_IWUSR);
module_param(ptr,charp,S_IRUSR|S_IWUSR);
module_param_array(a,int,NULL,S_IRUSR|S_IWUSR);

int set_param(const char *val,const struct kernel_param *kp)
{
	int res = param_set_int(val,kp);
	if(res == 0)
	{
		pr_info("CB func..\n");
		pr_info("cb_value changed to :%d\n",cb_val);
		return 0;
	}
	return -1;
}
module_param_cb(cb_val,&pops,&cb_val,S_IRUSR|S_IWUSR);
const struct kernel_param_ops pops=
{
	.set = &set_param,
	.get = &get_param,
}
static int __init param_init(void)
{
	pr_info("Val:%d\n",value);
	pr_info("ptr:%c\n",*ptr);
	for(int i=0;i<(sizeof(a)/sizeof(a[0]));i++)
	{		
		printf("a[%d] : %d\n",i,a[i]);
	}	
	pr_info("Inserted..\n");
	return 0;
}
static void __exit param_exit()
{
	pr_info("removed..\n");
}

module_init(param_init);
module_exit(param_exit);
