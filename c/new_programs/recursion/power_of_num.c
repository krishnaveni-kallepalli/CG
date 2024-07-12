#include<stdio.h>
int pow_rec(int base,int exp,int res)
{
	if(exp == 0) return res;
	res = res*base;
	return pow_rec(base,exp-1,res);
}
void power(int base,int exp)
{
	int res = 1,xp = exp;
	for(;exp!=0;exp--)
		res = res * base;
	printf("%d^%d is %d\n",base,xp,res);
}
int main()
{
	int base,exp;
	printf("Enter base,exp:");
	scanf("%d %d",&base,&exp);
	power(base,exp);
	int x = pow_rec(base,exp,1);
	printf("%d^%d is %d\n",base,exp,x);

}
