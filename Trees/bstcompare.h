#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *lchild, *rchild;
};

struct node *create(struct node *root, int data)
{
	if (root == NULL)
	{
		root = (struct node *)malloc(sizeof(struct node));
		root->data = data;
		root->lchild = root->rchild = NULL;
		return (root);
	}
	else if (data < root->data)
	{
		root->lchild = create(root->lchild, data);
	}
	else if (data > root->data)
	{
		root->rchild = create(root->rchild, data);
	}
	return root;
}

void display(struct node *temp)
{
	if (temp)
	{
		printf("%d\t", temp->data);
		display(temp->lchild);
		display(temp->rchild);
	}
}

int isIdentical(struct node *root1, struct node *root2)
{
	if (root1 == NULL && root2 == NULL)
		return 1;
	if (root1 != NULL && root2 != NULL && root1->data == root2->data)
		if (isIdentical(root1->lchild, root2->lchild) && isIdentical(root1->rchild, root2->rchild))
			return 1;
	return 0;
}

struct node *copy(struct node *root1)
{
	if (root1 == NULL)
		return root1;
	else
	{
		// create new node and make it a copy of node pointed by root
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->data = root1->data;			// copying data
		temp->lchild = copy(root1->lchild); // cloning left child
		temp->rchild = copy(root1->rchild); // cloning right child
		return temp;
	}
}
