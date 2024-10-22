#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
	int val;
	struct node *prev,*link;

}cdll;
cdll *head = NULL;
void create(int d)
{
	cdll *new = (cdll*)malloc(sizeof(cdll));
	new->val = d;
	new->prev = NULL;
	new->link = NULL;

	if(head == NULL)
	{
		head = new;
		head->prev = head;
		head->link = head;
	}
	else
	{
		cdll *ptr = head;
		do
		{
			ptr  = ptr->link;
		}while(ptr->link!=head);
		new->link = ptr->link;
		new->prev = ptr;
		ptr->link = new;
	}
}

void disp()
{
	cdll *ptr = head;
	do
	{
		printf("%d",ptr->val);
		ptr = ptr->link;
	}while(ptr!=head);
}

int main()
{
	create(3);
	create(4);
	create(5);
	disp();
	return 0;
}

