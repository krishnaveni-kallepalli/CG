#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
	int data;
	struct node *left;
	struct node *right;
}Tree;
Tree *root = NULL;
void create(int d)
{
	Tree *new = (Tree*)malloc(sizeof(Tree));
	new->data = d;
	new->left = NULL;
	new->right = NULL;
	if(root == NULL) 
		root = new;
	else
	{
		Tree *current = root;
		Tree *parent;
		while(current!=NULL)
		{
			parent = current;
			if(d < current->data)
				current = current->left;
			else if(d > current->data)
				current = current->right;
			else
			{
				free(new);
				return ;
			}
		}
		if(d < parent->data)
			parent->left = new;
		else
			parent->right = new;
	}

}
void inorder(Tree *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void preorder(Tree *root)
{
	if(root!=NULL)
        {
		printf("%d ",root->data);
                preorder(root->left);
                preorder(root->right);
        }
}
void postorder(Tree *root)
{
	if(root!=NULL)
        {
                postorder(root->left);
                postorder(root->right);
		printf("%d ",root->data);
        }
}
int size(Tree *root)
{
	if(root == NULL) return 0;
	else return size(root->left)+1+size(root->right);
}
void find_min_max(Tree *root)
{
	Tree *min = root;
	while(min->left!=NULL) min = min->left;
	printf("Min : %d\n",min->data);

	Tree *max = root;
	while(max->left!=NULL) max = max->right;
	printf("Max : %d\n",max->data); 
}
void search(Tree *root)
{
	int ele;
	printf("Enter element to search:");
	scanf("%d",&ele);
	if(root == NULL)
	{
		printf("Empty Tree..\n");
		return ;
	}
	else
	{
		Tree *current = root;
                Tree *parent;
                while(current!=NULL)
                {
                        parent = current;
                        if(ele < current->data)
			{
                                current = current->left;

			}
                        else if(ele > current->data)
                                current = current->right;
			else if (ele == current->data)
			{
				printf("%d found\n",ele);
				return ;
			}
              	}
		printf("%d not found\n", ele);
	}
}
void delete(Tree *root)
{
	int ele;
        printf("Enter element to delete:");
        scanf("%d",&ele);
	if(root == NULL)
        {
                printf("Empty Tree..\n");
                return ;
        }
        else
        {
                Tree *current = root;
                Tree *parent,*ptr;
                while(current!=NULL)
                {
                        parent = current;
			ptr = current;
                        if(ele < current->data)
                                current = current->left;
                        else if(ele > current->data)
                                current = current->right;
                        else if (ele == current->data)
                        {
                                printf("%d found\n",ele);
                               	return ;
                        }
		}
		if(current->left == NULL && current->right == NULL)
		{
			if(parent->left == current) parent->left = NULL;
			else if(parent->right == current) parent->right = NULL;
			free(current);
		}
		else if(current->left == NULL)
		{
			if (parent->left == current) parent->left = current->right;
    			else parent->right = current->right;
			free(current);
		}
		else if (current->right == NULL) 
		{
			if (parent->left == current) parent->left = current->left;
        		else parent->right = current->left;
			free(current);
       		}
       
	}
}
int main()
{
	int ch,data;
	while(1)
	{
	printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Size\n6.Min Max\n7.Search an element\n\n");
	printf("Enter choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("Insert ");
		       scanf("%d",&data);
		       create(data);
		       break;
		case 2:
		       printf("Inorder:");
		       inorder(root);
		       printf("\n");
		       break;
		case 3:
		       printf("Preorder:");
                       preorder(root);
                       printf("\n");
                       break;
		case 4:
		       printf("Postorder:");
                       postorder(root);
                       printf("\n");
                       break;
		case 5:printf("Size:%d\n",size(root));
		       break;
		case 6:find_min_max(root);
		       break;
		case 7:search(root);
		       break;
		default : printf("Invalid..\n");
			  exit(0);

	}}
	return 0;
}
