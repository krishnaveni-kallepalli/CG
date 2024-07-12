#include<stdio.h>
int pal_rec(int num,int rev)
{
	if(num==0) return rev;
	rev = (num%10)+rev*10;
	return pal_rec(num/10,rev);
}

void pal(int num)
{
	int x = num;
	int rem,rev = 0;
	while(x!=0)
	{
		rem = x%10;
		rev = rem+rev*10;
		x = x/10;
	}
	if(num == rev) printf("Palindrome\n");
	else printf("Not plaindrome\n");
}
int main()
{
	int num,rev=0;
	printf("ENter num:");
	scanf("%d",&num);
	pal(num);
	int res = pal_rec(num,rev);
	if(num == res) printf("Palindrome\n");
        else printf("Not plaindrome\n");
}
