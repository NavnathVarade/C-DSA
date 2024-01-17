#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *lchild, *rchild;
};

int cnt = 0, leafcnt = 0, nleafcnt = 0;

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

int count(struct node *temp)
{
	if (temp != NULL)
	{
		cnt++;
		count(temp->lchild);
		count(temp->rchild);
	}
	return cnt;
}

int countleaf(struct node *temp)
{
	if (temp != NULL)
	{
		if (temp->lchild == NULL && temp->rchild == NULL)
			leafcnt++;
		countleaf(temp->lchild);
		countleaf(temp->rchild);
	}
	return leafcnt;
}

int countnleaf(struct node *temp)
{
	if (temp != NULL)
	{
		if (temp->lchild != NULL || temp->rchild != NULL)
			nleafcnt++;
		countnleaf(temp->lchild);
		countnleaf(temp->rchild);
	}
	return nleafcnt;
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
