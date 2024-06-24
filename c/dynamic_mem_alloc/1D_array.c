#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *ptr;
	int size = 10;
	ptr = (int *)malloc(size*sizeof(int));
	if(ptr ==NULL)
	{
		printf("-ENOMEM");
		return 1;
	}

	printf("Enter elements:\n");
	for(int i=0;i<size;i++)
	{
		scanf("%d",ptr+i);
	}

	printf("Disp:\n");
	for(int i=0;i<size;i++)
		printf("%d ",*(ptr+i));
	printf("\n");

	free(ptr);
	return 0;


}
