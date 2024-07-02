#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node 
{
	int data;
	struct node *link;
};
struct node *head = NULL;
void create(int d)
{
	struct node *ptr=head;
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = d;
	new->link = NULL;
	if(head == NULL) head = new;
	else
	{
		while(ptr->link!=NULL)
			ptr = ptr->link;
		ptr->link = new;
	}
}
void ins_beg(int d)
{
	struct node *new = (struct node*)malloc(sizeof(int));
	new->data = d;
	new->link = NULL;
	if (head == NULL) head = new;

	else
	{
		new->link = head;
		head = new;
	}
}
void ins_pos(int d)
{
	int pos;
	struct node *new = (struct node*)malloc(sizeof(struct node));
	struct node *ptr = head;
	new->data = d;
	new->link = NULL;
	printf("Enter pos:");
	scanf("%d",&pos);
	for(int i = pos-1;i!=1;i--)
		ptr = ptr->link;
	new->link = ptr->link->link;
	ptr->link = new;
}
void find_mid()
{
	struct node *p=head,*q=head;
	while(q->link!=NULL && q!=NULL)
	{
		p = p->link;
        	q = q->link->link;
	}
	printf("Mid:%d\n",p->data);
}
void reverse()
{
	struct node *this = head;
	struct node *prev=NULL;
	struct node *next = NULL;

	while(this!=NULL)
	{
		next = this->link;
		this->link = prev;
		prev = this;
		this = next;
	}
	head = prev;
}
void del_beg()
{
	struct node *ptr = head;
	head = ptr->link;
	printf("Deleted element:%d\n",ptr->data);
	free(ptr);
}
void del_end()
{
	struct node *ptr = head,*q=head;
	while(ptr->link->link!=NULL)
		ptr=ptr->link;
	q=ptr->link;
	printf("Deleted element:%d\n",q->data);
	ptr->link = NULL;
	free(q);
}
void del_pos()
{
	int pos;
	struct node *ptr = head,*q=head;
	printf("ENter pos:");
	scanf("%d",&pos);
	for(int i=pos-1;i!=1;i--)
		ptr = ptr->link;
	q = ptr->link;
	ptr->link = q->link;
	printf("Deleted element:%d\n",q->data);
	free(q);
}
void disp()
{
	struct node *ptr = head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr = ptr->link;
	}
}
int main()
{
	create(23);
	create(32);
	create(34);
	create(56);
	ins_beg(98);
	ins_beg(78);
	ins_beg(65);
	disp();
	printf("\n");
	del_beg();
	del_end();
	disp();
	printf("\n");
	del_pos();
	disp();
	printf("\n");
	return 0;
}
