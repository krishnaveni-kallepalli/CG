#include<stdio.h>
void select(int a[],int n)
{
	int i,j,temp,min;
	for(i=0;i<n;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
			if(a[j] < a[min]) min = j;
		if(min!=i) a[i] = a[i] + a[min] - (a[min] = a[i]);
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

	void (*fp)(int [],int)=select;
	fp(a,n);

	printf("After sorting:\n");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;

}
