#include<stdio.h>
#include<limits.h>
void smallest(int a[],int n)
{
	int k,ksmall,high;
	printf("Enter k:");
	scanf("%d",&k);
	ksmall = 0;
	high = INT_MAX;
	for(int i=0;i<n;i++)
	{
		while(k!=0)
		{
 			if(a[i]<high)
				high = a[i];
			if(a[i]>ksmall && a[i]<high)
			{
				ksmall = a[i];
				k--;
			}
		}
		if(k==0)
		{
			printf("%d",ksmall);
			return ;
		}
	}
	printf("%d",ksmall);
}
int main()
{
	int a[100],n;
	printf("Enter size:");
	scanf("%d",&n);

	printf("Enter elements:\n");
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	smallest(a,n);
}
