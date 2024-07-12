#include<stdio.h>
int fact_rec(int num)
{
	if(num ==0||num==1) return 1;
	else return num*fact_rec(num-1);
}
void factorial(int num)
{
	int i,fact = 1;
	for(i=1;i<=num;i++)
		fact = fact*i;
	printf("Factorial of %d is %d\n",num,fact);
}
int main()
{
	int num;
	printf("ENter num:");
	scanf("%d",&num);
	printf("Factorial of %d is %d\n",num,fact_rec(num));
	factorial(num);
}
