#include<stdio.h>
void bubble(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j] >a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
int main()
{
	int a[10],n;
	printf("Enter size:");
	scanf("%d",&n);

	printf("ENter elements:\n");

	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	void (*fp)(int [],int)=bubble;
	fp(a,n);
	printf("After sorting:\n");

	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;

}
