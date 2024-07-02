#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top = -1;
void push(int *a,int data)
{
	if(top >= MAX -1) 
	{
		printf("Stack overflow.\n");
		return;
	}
	else
	{
		top++;
		a = realloc(a,(top+1)*sizeof(int)); 
		if(a==NULL) 
		{
			printf("Failed to allocate memory.\n");
			exit(1);
		}
		*(a+top) = data;
	}
}
void pop(int *a)
{
	if(top == -1) printf("Stack underflow\n");
	else top--;
}
void print(int *a)
{
	if(top == -1) printf("stack is Empty\n");
	else
	{
		for(int i=0;i<=top;i++)
			printf("%d ",*(a+i));
		printf("\n");
	}
}
int main()
{
	int *a;
	a = (int*)malloc(MAX*sizeof(int));
	if(a==NULL)
	{
		printf("Failed to allocate memory.\n");
		return -1;
	}
	push(a,23);
	push(a,33);
	push(a,44);
	print(a);
	pop(a);
	print(a);
}
