/*
Write a C program that accepts the vertices and edges of a graph and store it as an
adjacency matrix. Implement function to traverse the graph using Depth First Search(DFS)traversal.
*/

#include <stdio.h>

void DFS(int);
int v, G[10][10], visited[10], n;

void main()
{
	int i, j;
	printf("Enter number of vertices:");
	scanf("%d", &n);
	// read the adjecency matrix
	printf("\nEnter adjecency matrix of the graph:\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("Enter value for row %d, column %d: ", i, j);
			scanf("%d", &G[i][j]);
		}
	}

	// visited is initialized to zero
	for (i = 1; i <= n; i++)
		visited[i] = 0;
	printf("\nEnter the starting vertex : ");
	scanf("%d", &v);
	printf("\nDFS Traversal is : ");
	DFS(v);
}

void DFS(int i)
{
	int j;
	printf("%d->", i);
	visited[i] = 1;
	for (j = 1; j <= n; j++)
		if (!visited[j] && G[i][j] == 1)
			DFS(j);
}
