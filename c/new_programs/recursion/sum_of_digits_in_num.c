#include<stdio.h>
int num_sum_rec(int num)
{
	if(num == 0) return 0;
	else return (num %10) + num_sum_rec(num/10);	
}
int num_sum(int num)
{
	int sum=0,x=num,rem=0;
	while(x!=0)
	{
		rem = x%10;
		sum = sum + rem;
		x = x/10;
	}
	return sum;
}
int main()
{
	int num;
	printf("ENter num:");
	scanf("%d",&num);
	int x;
        x = num_sum(num);
	printf("Sum of digits in %d : %d\n",num,x);
	x = num_sum_rec(num);
        printf("Sum of digits in %d : %d\n",num,x);
	return 0;
}
