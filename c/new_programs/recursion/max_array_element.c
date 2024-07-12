#include<stdio.h>
int max_rec(int a[],int n,int max)
{
	if(n==0) return max;
	if(a[n-1]> max)
		max = a[n-1];
	max_rec(a,n-1,max);
}
void max_ele(int a[],int n)
{
	int max = a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i] > max)
			max = a[i];
	}
	printf("%d",max);
}

int main()
{
	int a[100],n;
	printf("Enter size:");
	scanf("%d",&n);

	printf("Enter array elements:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	max_ele(a,n);
	int res = max_rec(a,n,0);
	printf("%d",res);
}
