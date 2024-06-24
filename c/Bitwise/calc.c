#include<stdio.h>
int add(int a,int b)
{
	while(b!=0)
	{
		int carry = a&b;
		a = a^b;
		b = carry << 1;
	}
	return a;
}
int sub(int a,int b)
{
	b = ~b+1;
	return add(a,b);
}
int mul(int a,int b)
{
	int res = 0;
	while(b!=0)
	{
		if(b&1) res = res+a;
		a = a << 1;
		b = b >> 1;
	}
	return res;
}
int main()
{
	int a,b;
	printf("ENter a,b:");
	scanf("%d %d",&a,&b);
	printf("Add:%d\n",add(a,b));
	printf("ENter a,b:");
        scanf("%d %d",&a,&b);
	printf("Sub:%d\n",sub(a,b));
	printf("ENter a,b:");
        scanf("%d %d",&a,&b);
        printf("Mul:%d\n",mul(a,b));


}
