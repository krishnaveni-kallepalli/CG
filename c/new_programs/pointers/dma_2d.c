#include<stdio.h>
#include<stdlib.h>
void print(int **ptr,int m,int n)
{
	printf("Display:\n");
	for(int i=0;i<m;i++)
	{
		printf("[ ");
		for(int j=0;j<n;j++)
		{
			printf("%d ",*(*(ptr+i)+j));
		}
		printf("]\n");
	}
}
int main()
{
	int **ptr,m,n;
	printf("Enter mxn:");
	scanf("%d %d",&m,&n);
	ptr = (int **)malloc(m*sizeof(int*));
	printf("Enter elements:\n");
	for(int i=0;i<m;i++)
	{
		ptr[i] = (int *)malloc(n*sizeof(int));
		for(int j=0;j<n;j++)
			scanf("%d",&ptr[i][j]);
	}
	print(ptr,m,n);
	return 0;
}
