#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
	struct TreeNode *left;
	int data;
	struct TreeNode *right;
};

struct Qnode
{
	struct TreeNode *node;
	struct Qnode *next;
} *front, *rear;

void initQ()
{
	front = rear = NULL;
}

int isQEmpty()
{
	if (front == rear && rear == NULL)
	{
		printf("\nQueue Empty\n");
		return 1;
	}
	return 0;
}

void enqueue(struct TreeNode *Tnode)
{
	struct Qnode *nptr = (struct Qnode *)malloc(sizeof(struct Qnode));
	nptr->node = Tnode;
	nptr->next = NULL;
	if (rear == NULL)
	{
		front = nptr;
		rear = nptr;
	}
	else
	{
		rear->next = nptr;
		rear = rear->next;
	}
}

struct Qnode *dequeue()
{
	struct Qnode *temp;
	if (front == NULL)
	{
		printf("\n\nQueue is empty \n");
	}
	else
	{
		temp = front;
		front = front->next;
		if (temp == rear)
		{
			rear = front;
		}
	}
	return temp;
}

void levelOrderTraversal(struct TreeNode *root)
{
	struct TreeNode *curr, *ptr;
	int total, cnt, level;
	struct Qnode *temp;
	total = cnt = level = 0;
	enqueue(root);
	ptr = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	ptr->data = 0;
	ptr->left = ptr->right = NULL;
	enqueue(ptr);
	// enqueue(NULL);
	while (front != rear)
	{
		temp = dequeue();
		// printf("Dequeue temp=%d",temp->node->data);
		if (temp->node->data != 0)
		{
			total++;
			cnt++;
			printf("Node Value : %d\t", temp->node->data);
			if (temp->node->left != NULL)
			{
				// printf("Left Child : %d",temp->node->left->data);
				enqueue(temp->node->left);
			}
			if (temp->node->right != NULL)
			{
				// printf("Right Child : %d",temp->node->right->data);
				enqueue(temp->node->right);
			}
		}
		else
		{
			printf("\nNo of node in level %d = %d\n", level, cnt);
			cnt = 0;
			level++;
			ptr = (struct TreeNode *)malloc(sizeof(struct TreeNode));
			ptr->data = 0;
			ptr->left = ptr->right = NULL;
			enqueue(ptr);
		}
	}
	printf("\nNo of node in level %d = %d\n", level, cnt);
	cnt = 0;
	level++;
	printf("\nTotal Nodes= %d\nNumber of Levels = %d\n", total, level);
}

struct TreeNode *insert(struct TreeNode *root, int x)
{
	if (root == NULL)
	{
		root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
		root->data = x;
		root->left = root->right = NULL;
		return (root);
	}
	else if (x < root->data)
	{
		root->left = insert(root->left, x);
	}
	else if (x > root->data)
		root->right = insert(root->right, x);
	return (root);
}

void inorder(struct TreeNode *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf(" %d ", root->data);
		inorder(root->right);
	}
}
