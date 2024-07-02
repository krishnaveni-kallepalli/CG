#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	int data;
	struct tree *left,*right;
}Tree;
Tree *root = NULL;
void insert(int d)
{
	Tree *new = (Tree*)malloc(sizeof(Tree));
	new->data = d;
	new->left = NULL;
	new->right = NULL;
	if(root == NULL) root = new;
	else
	{
		Tree *current = root;
		Tree *parent;
		while(current!=NULL)
		{
			parent = current;
			if(d > current->data)
				current = current->right;
			else if( d < current->data)
				current = current->left;
			else
			{
				free(new);
				return ;
			}
		}
		if(d > parent->data)
			parent->right = new;
		else if(d < parent->data)
			parent->left = new;
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
void postorder(Tree *root)
{
        if(root!=NULL)
        {
                postorder(root->left);
                postorder(root->right);
		printf("%d ",root->data);
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
int main()
{
	insert(22);
	insert(33);
	insert(12);
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
}
