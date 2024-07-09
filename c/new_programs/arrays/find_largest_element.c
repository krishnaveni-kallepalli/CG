#include<stdio.h>
int largest_int(int a[],int n)
{
	int large = a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i] > large)
			large = a[i];
	}
	return large;
}
int main()
{
	int n;
	printf("Enter size:");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Largest element: %d\n",largest_int(a,n));
	return 0;
}
