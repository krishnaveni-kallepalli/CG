#include<stdio.h>
#include<stdlib.h>

int main()
{
	int **ptr;
	int r;
	int c;
	printf("Enter r,c:");
	scanf("%d %d",&r,&c);
	ptr = (int **)malloc(r*sizeof(int));
        printf("Enter elements:\n");	
	for(int i=0;i<r;i++)
	{
		ptr[i] = (int*)malloc(sizeof(int));
		for(int j = 0;j<c;j++)
		{
			scanf("%d",(*(ptr+i)+j));
		}
	}
	printf("Disp:\n");
	for(int i=0;i<r;i++)
        {
    
                for(int j = 0;j<c;j++)
                {
                        printf("%d ",*(*(ptr+i)+j));
                }
		printf("\n");
        }

	free(ptr);
}
