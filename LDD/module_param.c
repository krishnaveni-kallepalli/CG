#include<lunix/init.h>
#include<linuux/kernel.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

int x;
char *y;
int s[10];
int cb = 0;
module_param(x,int,S_IRUSR|S_IWUSR);
module_param(y,charp,S_IRUSR|S_IWUSR);
module_param_array(s,int,NULL,,S_IRUSR|S_IWUSR);


int set_fun(const char *val,const struct kernel_param *kp)
{
	int res = param_set_int(val,kp);
	if(res == 0)
	{
		pr_info("its cb fun..\n");
		pr_info("chanegd cb:%d\n",cb);
	       return 0;	
	}
	return -1;
}
const struct kernel_param_ops kpops = 
{
	.set = &set_fun,
	.get = &get_fun,
};
module_parma_cb(cb,&kpops,&cb,,S_IRUSR|S_IWUSR);
static int __init mpinit(void)
{
	printf("%d\n",x);
	printf("%c\n",*y);
	for(int i=0;i<(sizeof(s)/sizeof(s[0]));i++)
		pr_info("%d",s[i]);
	return 0;
}
static void __exit mpexit()
{
	pr_info("removed..\n");
}

module_init(mpinit);
module_exit(mpexit);
