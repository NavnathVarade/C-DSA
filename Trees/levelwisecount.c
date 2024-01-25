/*
Write a C program which uses Binary search tree library and displays nodes at each level,
count of node at each level and total levels in the tree.
*/

#include <stdio.h>
#include <stdlib.h>
#include "levelwisecount.h"

int main()
{
	int val, n, i;
	struct TreeNode *root;
	root = NULL;
	initQ();
	printf("\n#-#-#-\t\tBST Construction\t-#-#-#\n");
	printf("\nEnter number of nodes you want : ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("\nEnter The Tree Node Data of %dth node : ", i + 1);
		scanf("%d", &val);
		root = insert(root, val);
	}
	printf("\n\n\tLevel Order Traversal\n");
	levelOrderTraversal(root);
	return 0;
}
