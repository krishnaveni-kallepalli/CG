#include<stdio.h>
void remove_dupe(int a[],int n)
{
	int i,j,count;
	for(i=0;i<100;i++)
	{
		count = 0;
		for(j=0;j<n;j++)
		{
			if(a[j] == i)
				count++;
		}
		if(count>0) printf("%d ",i);
	}
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
	remove_dupe(a,n);
	return 0;
}
