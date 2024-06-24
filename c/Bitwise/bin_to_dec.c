#include<stdio.h>
#include<math.h>
#define NBITS sizeof(int)*2
void from_msb_btod(int x)
{
	int msb = 1 << (NBITS-1);
	int res = 0;
	double exp = NBITS-1;
	for(int i=NBITS;i>0;i--,exp--)
	{
		int fb = (msb&x) >> (NBITS-1);
		res = res + fb*pow(2,exp);
		x = x << 1;
	}
	printf("Dec : %d\n",res);
}
/*
void from_lsb_btod(int x)
{
	int res = 0;
	double exp = 0;
	for (int i=0;i<NBITS;i++,exp++)
	{
		int lb = x&1;
		res = res + lb*pow(2,exp);
		x = x >> 1;
	}
	printf("Dec : %d\n",res);
}
*/
void from_lsb_btod(int x)
{
        int res = 0;
       // double exp = 0;
        for (int i=0;i<NBITS;i++)
        {
                int lb = x&1;
                res = res + lb*pow(2,i);
                x = x >> 1;
        }
        printf("Dec : %d\n",res);
}
int main()
{
	int x = 0b00000111;
	from_msb_btod(x);
	from_lsb_btod(x);

}
