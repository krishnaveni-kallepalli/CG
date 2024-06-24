#include<stdio.h>
#define NBITS sizeof(int)*2
void lsb_check(int x)
{
	printf("LSB:%d\n",x&1);
}
void msb_check(int x)
{
	int msb = (1 << NBITS-1);
	printf("MSB:%d\n",(x&msb)>>(NBITS-1));
}
void set(int x,int pos)
{
	x |= (1<<pos);
       printf("After setting %d : %d\n",pos,x);	
}
void clear(int x,int pos)
{
        x &= ~(1<<pos);
       printf("After clearing %d : %d\n",pos,x);
}
void toggle(int x,int pos)
{
        x ^= (1<<pos);
       printf("After toggling %d : %d\n",pos,x);
}
void leading(int x)
{
	int count = 0;
	int msb = 1 << (NBITS-1);
	for(int i = NBITS;i>=0;i--)
	{
		if(msb&x) break;
		count++;
		x = x<<1;
	}
	printf("Count = %d\n",count);
}

void trailing(int x)
{
	int count =0;
	for(int i=0;i<NBITS;i++)
	{
		if(x&1) break;
		count ++;
		x = x >> 1;
	}
	printf("Count :%d\n",count );
}
int main()
{
	int x,pos;
	/*
	printf("Enter num:");
	scanf("%d",&x);
	lsb_check(x);
	msb_check(x);
	printf("Enter pos:");
	scanf("%d",&pos);
	set(x,pos);
	printf("Enter pos:");
        scanf("%d",&pos);
	clear(x,pos);
	printf("Enter pos:");
        scanf("%d",&pos);
	toggle(x,pos);
*/
	 printf("Enter num:");
        scanf("%d",&x);
        leading(x);
	trailing(x);
}
