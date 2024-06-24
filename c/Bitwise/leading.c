#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define NBITS sizeof(int)*2
int check_LSB(int x)
{
	return x&1;
}
int check_MSB(int x)
{
	int msb = 1 << (NBITS-1);
	return (x&msb)>>(NBITS-1);// shifting by n-1 bits to get msb
}
int get_bit(int x,int n)
{
	return (x>>n)&1;
}
void dec2bin(int x)
{
	for(int i=NBITS-1;i>=0;i--)
		printf("%d",(x>>i)&1);
}
int bin2dec(int x)
{
	int rem,dec=0,i=0;
	while(x!=0)
	{
		rem = x%10;
		x=x/10;
		dec = dec+rem*pow(2,i);
		i++;
	}
	return dec;
}
int leading_zeros(int x)
{
	int zeros=0;
	for(int i=0;i<NBITS;i++)
	{
		if(x>>i) break;
		zeros++;
	}
	return zeros;
}
int main()
{
	int x,ch,n;
	while(1)
	{
		printf("\n\n1.LSB\n2.MSB\n3.Get nth bit\n4.Decimal to Binary\n5.Decimal to Binary\n6.Leading Zeros\n\n");
		printf("Enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter num:");
			scanf("%d",&x);
			printf("LSB:%d\n",check_LSB(x));
			break;
			case 2:
			printf("Enter num:");
			scanf("%d",&x);
			printf("MSB:%d\n",check_MSB(x));
			break;
			case 3:
			printf("Enter num:");
			scanf("%d",&x);
			printf("Enter nth bit:");
			scanf("%d",&n);
			printf("Nth bit:%d\n",get_bit(x,n));
			break;
			case 4:
			printf("Enter num:");
			scanf("%d",&x);
			dec2bin(x);
			break;
			case 5:
			printf("Enter num:");
			scanf("%d",&x);
			printf("%d\n",bin2dec(x));
			break;
			case 6:
			printf("Enter num:");
			scanf("%d",&x);
			printf("%d\n",leading_zeros(x));
			break;
			default:
			printf("Invalid choice \n");
			exit(1);
		}
	}
	return 0;
}
