#include<stdio.h>
int n_sum(int range,int sum)
{
	if(range==0) return sum;
	sum = sum+range;
	n_sum(range-1,sum);
}
int main()
{
	int range;
	printf("ENter range:");
	scanf("%d",&range);

	int x = n_sum(range,0);

	printf("Sum of %d:%d\n",range,x);
}
