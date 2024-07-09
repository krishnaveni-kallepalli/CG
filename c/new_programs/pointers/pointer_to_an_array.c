#include<stdio.h>
int main()
{
	int a[5];
	int (*p)[5] = &a;
	printf("Enter elements:\n");
	for(int i=0;i<5;i++)
		scanf("%d",&(*p)[i]);
	printf("Display:\n");
	for(int i=0;i<5;i++)
		printf("%d ",(*p)[i]);
	printf("\n");
}
