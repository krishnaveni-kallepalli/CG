#include<stdio.h>
int main()
{
	int *p[5],a[5];
	for(int i=0;i<5;i++)
		p[i] = &a[i];
	printf("Enter elements:\n");
	for(int i=0;i<5;i++)
		scanf("%d",p[i]);
	printf("Display:\n");
	for(int i=0;i<5;i++)
		printf("%d ",*p[i]);
	printf("\n");

}
