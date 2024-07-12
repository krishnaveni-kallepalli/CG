#include<stdio.h>
void value(void (*fp)(int a))
{
	int a;
        printf("Enter a:");
        scanf("%d",&a); 
	printf("This is cb_fun with args:");
	fp(a);
}
void val(int a)
{
	printf("a:%d\n",a);
}
int main()
{
	void (*fp)(int) = val;
	value(fp);
}
