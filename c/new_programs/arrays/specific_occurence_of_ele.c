#include<stdio.h>
int count_specific(int a[],int n, int num)
{
	int i,count=0,flag=0;
	for(i=0;i<n;i++)
	{
		if(a[i] == num)
		{
			flag =1;
			count ++;
		}
	}
	return count;
}
int main()
{
        int n,num;
        printf("Enter size:");
        scanf("%d",&n);
        int a[n];
        printf("Enter elements:\n");
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
	printf("Enter element:");
        scanf("%d",&num);
	if(count_specific(a,n,num)==0) printf("Element is not listed in array\n");
	else printf("Count of %d is %d\n",num,count_specific(a,n,num));
	return 0;
}
