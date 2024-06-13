#include<stdio.h>
int main()
{
	int range,i,j;
	printf("Enter range :");
	scanf("%d",&range);
	for(i=2;i<range;i++)
	{
		int flag = 1;
		for(j=2;j<i;j++)
		{
			if(i%j==0) 
			{
				flag=0;
				break;
			}
		}
		if(flag==1) printf("%d ",i);
	}
}

a
