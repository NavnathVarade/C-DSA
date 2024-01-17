/*
Write a program which uses binary search tree library and counts the total nodes and
total leaf nodes in the tree.
int count(T) – returns the total number of nodes from BST
int countLeaf(T) – returns the total number of leaf nodes from BST
*/

#include <stdio.h>
#include <stdlib.h>
#include "count.h"

int main()
{
	struct node *root = NULL, *temp;
	int n, i, ch, val, cnt;
	do
	{
		printf("\n-----MENU-----\n");
		printf("\n1. Create BST.");
		printf("\n2. Display BST.");
		printf("\n3. Count Total Number of Nodes.");
		printf("\n4. Count Total Number of Leaf Nodes.");
		printf("\n5. Count Total Number of Non-Leaf Nodes.");
		printf("\n6. Exit.");
		printf("\nEnter Your Choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\nEnter how many nodes you want : ");
			scanf("%d", &n);
			for (i = 0; i < n; i++)
			{
				printf("\nEnter node values for %dth node : ", i + 1);
				scanf("%d", &val);
				root = create(root, val);
			}
			break;

		case 2:
			display(root);
			break;

		case 3:
			cnt = count(root);
			printf("\nTotal Number of Nodes = %d", cnt);
			break;

		case 4:
			cnt = countleaf(root);
			printf("\nTotal Number of Leaf Nodes = %d", cnt);
			break;
		case 5:

			cnt = countnleaf(root);
			printf("\nTotal Number of Non-Leaf Nodes = %d", cnt);
			break;
		case 6:
			exit(0);
			break;

		default:
			printf("\nInvalid Choice.");
		}
	} while (ch != 6);
	return 0;
}
