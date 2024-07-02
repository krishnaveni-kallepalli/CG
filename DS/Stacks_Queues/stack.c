#include<stdio.h>
#include<stdlib.h>
#define STACK_LIMIT 10
int top = -1;
void push(int a[],int data)
{
	int i;
	if(top >= STACK_LIMIT-1) 
	{
		printf("stack overflow\n");
		return ;
	}
	else
	{
		top ++;
		a[top] = data;
	}
}
void pop(int a[])
{
	if(top == -1) printf("Satck underflow\n");
	else 
	{
		printf("popped element:%d\n",a[top]);
		top--;
	}
}
void print(int a[])
{
	printf("\nDisplay:\n");
	if(top == -1) printf("Empty\n");
	for(int i=0;i<=top;i++)
		printf("%d ",a[i]);
	printf("\n");
}

int main()
{
	int a[STACK_LIMIT],ch,data;
	while(1)
        {
	printf("\n1.push\n2.pop\n3.Display\n\n");
	printf("Enter choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("ENter data:");
			scanf("%d",&data);
			push(a,data);
			break;
		case 2:
			pop(a);
			break;
		case 3:
			print(a);
			break;
		default:
			printf("Invalid..\n");
			exit(0);
	}
	}
}
