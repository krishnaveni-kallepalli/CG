#include<stdio.h>
void reverse(int a[],int n)
{
	int i,j;
	for(i=0;i<n/2;i++)
	{
		j = n-1-i;
		int temp; 
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	printf("After revsersing array:\n");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int main()
{
	int n;
	printf("Enter size:");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements:\n");
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	reverse(a,n);
	return 0;
}
