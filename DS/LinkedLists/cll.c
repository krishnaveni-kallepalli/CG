#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}Node;
Node *head = NULL;
void create(int d)
{
	Node *new = (Node*)malloc(sizeof(Node));
	Node *ptr = head;
	new->data = d;
	new->link = NULL;

	if(head == NULL)
	{
		head = new;
		new->link = head;
	}
	else
	{
		while(ptr->link!=head)
			ptr = ptr->link;
		new->link = head;
		ptr->link = new;
	}
}
void ins_beg(int d)
{
	Node *new = (Node*)malloc(sizeof(Node));
        Node *ptr = head;
        new->data = d;
        new->link = NULL;

        if(head == NULL)
        {
                head = new;
                new->link = head;
        }
        else
	{
		new->link = ptr;
		while(ptr->link!=head)
			ptr = ptr->link;
		ptr->link = new;
		head = new;
	}
}
void ins_pos(int d)
{
	Node *new = (Node*)malloc(sizeof(Node));
        Node *ptr = head;
        new->data = d;
        new->link = NULL;
	int pos;
	printf("ENter pos:");
	scanf("%d",&pos);
        if(head == NULL)
        {
                head = new;
                new->link = head;
        }
	else
	{
		for(int i=pos-1;i!=1;i--)
			ptr = ptr->link;
		new->link = ptr->link;
		ptr->link = new;
	}

}
void del_beg()
{
	Node *ptr = head,*q=head;
	if(head ==NULL);
	else
	{
		while(ptr->link!=head)
			ptr = ptr->link;
		head = q->link;
		ptr->link = head;
		printf("Deleted element:%d\n",q->data);
		free(q);
	}
}
void del_end()
{
	Node *ptr = head,*q=head;
	if(head ==NULL);
	else
	{
		while(ptr->link->link!=head)
			ptr = ptr->link;
		q=ptr->link;
		ptr->link = head;
		printf("Deleted element:%d\n",q->data);
		free(q);	
	}
}
void size()
{
	Node *ptr = head;
	int size =1;
	do
	{
		size++;
		ptr=ptr->link;
	}while(ptr->link!=head);
	printf("Size:%d\n", size);
}
void disp()
{
	Node *ptr = head;
	printf("Disp:\n");
	while(ptr->link!=head)
	{
		printf("%d ",ptr->data);
		ptr = ptr->link;
	}
	printf("%d ",ptr->data);
	printf("\n");
}
int main()
{
	create(23);
	create(33);
	create(45);
	ins_beg(11);
	ins_pos(22);
	disp();
	del_end();
	disp();
	size();
}
