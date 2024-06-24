#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **a;
	int **b;
	int r,c;
	printf("Enter r,c");
	scanf("%d %d",&r,&c);
	a = (int **)malloc(r*sizeof(int));
	b = (int **)malloc(r*sizeof(int));
	printf("Enter array a:\n");
	for(int i=0;i<r;i++)
	{
		a[i] = (int *)malloc(sizeof(int));
		for(int j=0;j<c;j++)
		{
			scanf("%d",(*(a+i)+j));
		}
	}
	printf("Enter array b:\n");
	for(int i=0;i<r;i++)
	{
		b[i] = (int*)malloc(sizeof(int));
		for(int j=0;j<c;j++)
		{
			scanf("%d",(*(b+i)+j));
		}
	}

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			*(*(a+i)+j) = *(*(a+i)+j) + *(*(b+i)+j);
		}
	}

	printf("Disp:\n");
	for(int i=0;i<r;i++)
        {
                for(int j=0;j<c;j++)
                {
                        printf("%d ",*(*(a+i)+j));
                }
		printf("\n");
        }
	free(a);
	free(b);
}

