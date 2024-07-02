#include<stdio.h>
void insert(int a[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp = a[i];
		for(j=i-1;j>=0&&a[j]>temp;j--)
			a[j+1] = a[j];
		a[j+1]=temp;
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

	void (*fp)(int [],int)=insert;
	fp(a,n);
	printf("After sorting:\n");

	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;

}
