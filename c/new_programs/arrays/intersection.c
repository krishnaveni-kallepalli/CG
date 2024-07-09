#include<stdio.h>
void intersection(int a[],int b[],int n, int m)
{
	int i,j,flag;
	for(i=0;i<n;i++)
	{
		flag = 0;
		for(j=0;j<m;j++)
		{
			if(a[i] == b[j])
				flag = 1;
		}
		if(flag == 1) printf("%d ",a[i]);
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

	 int m;
        printf("Enter size:");
        scanf("%d",&m);
        int b[m];
        printf("Enter elements:\n");
        for(int i=0;i<m;i++)
                scanf("%d",&b[i]);

	intersection(a,b,n,m);
	return 0;
}
