#include<stdio.h>
void subset(int a[],int n)
{
	int i,j,k;
	int sub[n];
	for(i=0;i<2*n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\n",a[j]);
		}
		printf("");
	}
}
int main()
{
	int a[100],n;
	printf("Enter size:");
	scanf("%d",&n);

	printf("Enter elements:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	subset(a,n);
}
