#include<stdio.h>
int ndigits_rec(int num,int count)
{
	if(num==0) return count;
	ndigits_rec(num/10,count+1);
}

void n_digits(int num)
{
	int x = num;
	int count = 0;
	while(x!=0)
	{
		x = x/10;
		count ++ ;
	}
	printf("Count : %d\n",count);
}
int main()
{
	int num,rev=0;
	printf("ENter num:");
	scanf("%d",&num);
	n_digits(num);
	int res = ndigits_rec(num,0);
	printf("Count : %d\n",res);
}

Print all subsets of a set using recursion
