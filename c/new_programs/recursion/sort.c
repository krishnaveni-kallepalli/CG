#include<stdio.h>
void sort_rec(int a[],int n)
{
	int i;
	if (n<=1) return ;
	for(i=0;i<n-1;i++)
	{
		if(a[i] > a[i+1])
		{
			int temp = a[i];
			a[i] = a[i+1];
			a[i+1] = temp;
		}
	}
	sort_rec(a,n-1);
}
int main()
{
	int a[100],n;
	printf("Enter size:");
	scanf("%d",&n);

	printf("Enter elements:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort_rec(a,n);
	printf("Sorted array: ");
	for (int i = 0; i < n; i++)
        	printf("%d ", a[i]);
    	printf("\n");


}
