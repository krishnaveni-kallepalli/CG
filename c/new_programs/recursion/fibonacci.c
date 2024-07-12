#include<stdio.h>
int fib_rec(int n1,int n2, int range)
{
	if(range == 0) return n1;
	else
	{
		int n3 = n1+n2;
		return fib_rec(n2,n3,range-1);	
	}
}
int fib(int range)
{
	if(range <=1)
		return range;
	else
		return fib(range-1)+fib(range-2);
}
void fibonacci(int n1,int n2,int range)
{
	int i,n3;
	printf("%d %d ",n1,n2);
	for(i=2;i<range;i++)
	{
		n3 = n1+n2;
		printf("%d ",n3);
		n1=n2;
		n2=n3;
	}
}
int main()
{
	int range,n1=0,n2=1;
	printf("Enter range:");
	scanf("%d",&range);
	int x;
	for(int i=0;i<range;i++)
	{
        	x = fib_rec(n1,n2,i);
		printf("%d ",x); 
	}
	printf("\n");
	fibonacci(n1,n2,range);
	printf("\n");
	for(int i=0;i<range;i++)
	{
		x = fib(i);
		printf("%d ",x);
	}
	printf("\n");

	return 0;
}
