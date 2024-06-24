#include<stdio.h>
#define NBITS sizeof(int)*2
void dtob(int x)
{
	int msb = 1 << (NBITS-1);
	for(int i=NBITS;i>0;i--)
	{
		printf("%d ",(msb&x) >> (NBITS-1));
		x = x << 1;
	}
	printf("\n");
}
int main()
{
	int x;
	printf("ENter num:");
	scanf("%d",&x);

	dtob(x);
}
