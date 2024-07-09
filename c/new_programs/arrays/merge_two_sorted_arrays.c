#include<stdio.h>
void merge(int a[],int b[],int m,int n)
{
	int i,j,len = n+m;
	int c[len];
	for(i=0;i<n;i++)
		c[i] = a[i];
	for(j=0;j<m;j++)
		c[i+j] = b[j];
	printf("After Merging:\n");
	for(i=0;i<len;i++)
		printf("%d ",c[i]);
	printf("\n");
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
	int m;
        printf("Enter size:");
        scanf("%d",&m);
        int b[m];
        printf("Enter elements:\n");
        for(int i=0;i<m;i++)
                scanf("%d",&b[i]);
	merge(a,b,m,n);
}
