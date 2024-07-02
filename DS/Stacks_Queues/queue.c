#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int front = -1;
int rear = -1;
void enque(int a[],int data)
{
	if(rear >= MAX-1) printf("Reached limit\n");
	else
	{
		front = 0;
		rear ++;
		a[rear] = data;
	}
}
void deque(int a[])
{
	if(front == -1 && rear == -1)
               printf("Empty queue..\n");
        else
        {
		printf("1.first\n2.last\n");
		int ch;
		printf("Enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Dequeued element:%d\n",a[front]);
				front++;
			break;

			case 2 :
			printf("Dequeued element:%d\n",a[rear]);
                	rear --;
                	if(rear == -1)
                        	front = -1;
			break;
		}
        }
}
void print(int a[])
{
	printf("\nDisplay:\n");
	if(front == -1 && rear == -1)
	       printf("Empty queue..\n");
	else
	{
		for(int i=front;i<=rear;i++)
			printf("%d ",a[i]);
	}
	printf("\n");

}
int main()
{
	int a[MAX],ch,data;
	while(1)
	{
	printf("\n1.Enque\n2.Deque\n3.Display\n\n");
	printf("Enter choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("Enter data:");
			scanf("%d",&data);
			enque(a,data);
			break;
		case 2:
			deque(a);
			break;
		case 3:
			print(a);
			break;
		default:printf("invalid..\n");
			exit(0);
	}
	}
}
