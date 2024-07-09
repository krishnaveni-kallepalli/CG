#include<stdio.h>
int sum_ele(int a[],int n)
{
	int i,sum=0;
	for(i=0;i<n;i++)
		sum = sum + a[i];
	return sum;
}
int main()
{
	int n ;
	printf("Enter size:");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements:\n");
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	printf("Sum of %d elements are %d\n",n,sum_ele(a,n));
	return 0;

}
