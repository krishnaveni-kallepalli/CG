#include<stdio.h>
void major(int a[],int size)
{
	int i,j,count,x;
	for(i=0;i<size;i++)
	{
		count = 0;
		for(j=0;j<size;j++)
		{
			if(a[j] == a[i])
			{
				count++;
			}
		}
		
		if(count > size/2)
		{
			printf("Major element:%d\n",a[i]);
			return ;
		}
	}
}
int main()
{
	int a[100],n;
	printf("Enter szie:");
	scanf("%d",&n);
	printf("Enter elements:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	major(a,n);
}
