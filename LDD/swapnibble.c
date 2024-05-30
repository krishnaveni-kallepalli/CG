#include<stdio.h>
void even(int s, int e)
{
	if(s>e) return;
	if(s%2==0) printf("%d ",s);
	even(s+1,e);
}

int main()
{
	int num = 12321;
	int rev=0,rem=0;
	int x = num;
	while(x!=0)
	{
		rem  = x %10;
		rev = rem+rev*10;
		x = x/10;
	}	
	if(rev == num) printf("pal");
	else printf("Not\n");



	int n = 0x12;	
	int res;
	res = ((n & 0xF0) >> 4)| ((n&0x0F) << 4);
	printf("%x",res);

	int s=0,e=100;

	even(s,e);

}

