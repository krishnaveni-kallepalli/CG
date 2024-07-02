#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
	int data;
	struct node *prev,*next;
}Node;
Node *head = NULL;

void create(int d)
{
	Node *new = (Node*)malloc(sizeof(Node));
	Node *ptr = head;
	new->data = d;
	new->prev = NULL;
	new->next = NULL;
	if(head == NULL) 
	{
		head = new;
		head->prev = NULL;
	}
	else
	{
		while(ptr->next!=NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
	}
}
void ins_beg(int d)
{
	Node *new = (Node*)malloc(sizeof(Node));
        Node *ptr = head;
        new->data = d;
        new->prev = NULL;
        new->next = NULL;
	if(head == NULL)
        {
                head = new;
                head->prev = NULL;
        }
	else
	{
		new->next = head;
		head = new;
	}
}
void ins_pos(int d)
{
	Node *new = (Node*)malloc(sizeof(Node));
	Node *ptr = head;
	int pos;
	new->data = d;
	new->next = NULL;
	new->prev = NULL;
	printf("Enter pos:"); 
	scanf("%d",&pos);
	if(head==NULL) 
	{
		head = new ;
		head->prev = NULL;
	}
	else
	{
		for(int i=pos-1;i!=1;i--)
			ptr = ptr->next;
		new->next = ptr->next;
                new->prev = ptr;
		ptr->next->prev = new;
		ptr->next = new;
	}
}
void del_beg()
{
	Node *ptr = head;
	if(head == NULL) printf("no nodes to delete..\n");
	else
	{
		head = ptr->next;
		head->next->prev = NULL;
	}
	printf("Deleted element:%d\n",ptr->data);
	free(ptr);
}
void del_end()
{
	Node *ptr=head,*q=head;
	while(ptr->next->next!=NULL)
		ptr = ptr->next;
	q=ptr->next;
	ptr->next = NULL;
	printf("Deleted element:%d\n",q->data);
	free(q);
}
void del_pos()
{
	int pos;
	printf("ENter pos:");
	scanf("%d",&pos);
	Node *ptr = head,*q=head;
	for(int i=pos-1;i!=1;i--)
		ptr = ptr->next;
	q=ptr->next;
        q->next->prev = ptr;
        ptr->next = q->next;
        printf("Deleted element:%d\n",q->data);
        free(q);
}
void find()
{
	Node *ptr = head;
	int find,flag=0,count=1;
	printf("ENter node to find:");
	scanf("%d",&find);
	while(ptr!=NULL)
	{
		if(ptr->data == find)
		{	
			flag=1;
			break;
		}
		count++;
		ptr = ptr->next;
	}
	if(flag == 1) printf("Found at %d\n",count);
	else printf("No node\n");

}
void update_data()
{
	Node *ptr = head;
	int find,flag=0,newdata;
	printf("ENter node to find:");
        scanf("%d",&find);
	printf("Enter new data:");
	scanf("%d",&newdata);
        while(ptr!=NULL)
        {
                if(ptr->data == find)
                {
                        flag=1;
			ptr->data = newdata;
                        break;
                }
                ptr = ptr->next;
        }
        if(flag == 1) printf("updated data:%d\n",ptr->data);
	else printf("No node found to update data\n");
}
int size()
{
	Node *ptr = head;
	int size=0;
	while(ptr!=NULL)
	{
		size++;
		ptr=ptr->next;
	}
	return size;
}
void sort()
{
	if(head==NULL || head->next == NULL)
		printf("No need to sort..\n");
	else
	{

		int len = size();
		for(int i=len;i!=0;i--)
		{
			Node *p=head;
			while(p->next!=NULL)
			{
				if(p->data > p->next->data)
				{
					int temp;
					temp = p->data;
					p->data = p->next->data;
					p->next->data = temp;
				}
				p = p->next;
			}
		}
	}
}
void disp()
{
	struct node *ptr = head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}
int main()
{
	create(23);
	create(34);
	create(45);
	create(78);
	ins_beg(99);
	ins_pos(88);
	disp();
	sort();
	disp();
	return 0;
}
