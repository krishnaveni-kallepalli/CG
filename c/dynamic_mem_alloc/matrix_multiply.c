#include<stdio.h>
#include<stdlib.h>

int main()
{
	int **a;
	int **b;
	int **mul;
	int r,c;
	printf("Enter r,c");
	scanf("%d %d",&r,&c);
	a = (int **)malloc(r * sizeof(int *));
    	b = (int **)malloc(r * sizeof(int *));
    	mul = (int **)malloc(r * sizeof(int *));
    	for (int i = 0; i < r; i++) 
	{
        	a[i] = (int *)malloc(c * sizeof(int));
        	b[i] = (int *)malloc(c * sizeof(int));
        	mul[i] = (int *)malloc(c * sizeof(int));
    	}
	printf("Enter array a:\n");
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			scanf("%d",(*(a+i)+j));
		}
	}
	printf("Enter array b:\n");
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			scanf("%d",(*(b+i)+j));
		}
	}

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			*(*(mul+i)+j) = 0;
		}
	}
	for(int i=0;i<r;i++)
        {
                for(int j=0;j<c;j++)
                {
			for (int k = 0; k < c; k++) 
			{
                		*(*(mul + i) + j) += (*(*(a + i) + k)) * (*(*(b + k) + j));
            		}

                }
        }
	printf("Disp:\n");
	for(int i=0;i<r;i++)
        {
                for(int j=0;j<c;j++)
                {
                        printf("%d ",*(*(mul+i)+j));
                }
		printf("\n");
        }
	
	for(int i=0;i<r;i++)
	{
		free(a[i]);
		free(b[i]);
		free(mul[i]);
	}
	free(a);
	free(b);
	free(mul);

}

