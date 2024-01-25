/*
Write a C program which uses Binary search tree library and implements following
function with recursion:
T copy(T) – create another BST which is exact copy of BST which is passed as parameter.
int compare(T1, T2) – compares two binary search trees and returns 1 if they are equal
and otherwise.
*/

#include <stdio.h>
#include <stdlib.h>
#include "bstcompare.h"

int main()
{
	int ch, n, i, val, cnt, flag = 0;
	struct node *root1, *root2, *temp;
	root1 = NULL;
	root2 = NULL;

	while (1)
	{
		printf("\n---Binary Search Tree---\n");
		printf("1.Create First Tree.\n");
		printf("2.Create Second Tree.\n");
		printf("3.Display First Tree.\n");
		printf("4.Display Second Tree.\n");
		printf("5.Compare Both the Trees.\n");
		printf("6.Copy One Tree to Other.\n");
		printf("7.Exit.\n");
		printf("\nEnter your choice:");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			printf("\nCreate First Tree : ");
			printf("\nEnter how many nodes you want : ");
			scanf("%d", &n);
			for (i = 0; i < n; i++)
			{
				printf("\nEnter node values for %dth node : ", i + 1);
				scanf("%d", &val);
				root1 = create(root1, val);
			}
			break;

		case 2:
			printf("Create Second Tree : \n");
			printf("\nEnter how many nodes you want : ");
			scanf("%d", &n);
			for (i = 0; i < n; i++)
			{
				printf("\nEnter node values for %dth node : ", i + 1);
				scanf("%d", &val);
				root2 = create(root2, val);
			}
			break;

		case 3:
			printf("\nFirst BST Tree : ");
			display(root1);
			break;

		case 4:
			printf("\nSecond BST Tree :");
			display(root2);
			break;

		case 5:
			printf("Comparing Two Trees\n");
			flag = isIdentical(root1, root2);
			if (flag == 0)
				printf("\nBoth Trees are not Identical.\n");
			else
				printf("\nBoth Trees are Identical.\n");
			break;

		case 6:
			printf("\nCopying First BST Tree : ");
			copy(root1);
			printf("\nCopied First BST Tree is : ");
			display(root1);
			printf("\nCopying Second BST Tree : ");
			copy(root2);
			printf("\nCopied Second BST Tree is : ");
			display(root2);
			break;

		case 7:
			exit(0);
			
		default:
			printf("\nInvalid Choice\n");
		}
	}
}
