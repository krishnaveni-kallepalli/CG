#include<stdio.h>
#include<stdlib.h>
void print(int *ptr,int size)
{
	printf("Display:\n");
	for(int i=0;i<size;i++)
		printf("%d ",*(ptr+i));
	printf("\n");
}
int main()
{
	int *ptr,size;
	printf("Enter array size:");
	scanf("%d",&size);

	ptr = (int*)malloc(size * sizeof(int));

	printf("ENter array elements:");
	for(int i=0;i<size;i++)
		scanf("%d",ptr+i);

	print(ptr,size);

	return 0;
}
