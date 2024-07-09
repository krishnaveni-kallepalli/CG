#include<stdio.h>
void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void arithmetic(int *a,int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
void bitwise_swap(int *a,int *b)
{
	 *a = *a ^ *b;
	 *b = *a ^ *b;
	 *a = *a ^ *b;
}
void arth_swap(int *a,int *b)
{
	*a = (*a)*(*b);
         *b = *a / *b;
         *a = *a / *b;
}
int main()
{
	int a,b;
	printf("Enter a,b:");
	scanf("%d %d",&a,&b);
	printf("\nBefore swapping:\n");
        printf("%d %d\n",a,b);
	void (*fp[4])(int *,int *) = {swap,arithmetic,bitwise_swap,arth_swap};
	for(int i=0;i<3;i++)	
	{
		fp[i](&a,&b);
		printf("After swapping\n");
		printf("%d %d\n",a,b);
	}
}
