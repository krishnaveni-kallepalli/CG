#include<stdio.h>
int sum_rec(int a[],int n,int sum)
{
	if(n==0) return sum;
	sum = sum+a[n-1];
	sum_rec(a,n-1,sum);
}
void sum_array(int a[],int n)
{
	int sum = 0;
	for(int i=0;i<n;i++)
		sum = sum +a[i];
	printf("%d",sum);
}

int main()
{
	int a[100],n;
	printf("Enter size:");
	scanf("%d",&n);

	printf("Enter array elements:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int res = sum_rec(a,n,0);
	printf("%d",res);
}
