/*
Write a C program for the implementation of Floyd Warshall’s algorithm for finding all pairs shortest path using adjacency cost
matrix.
*/

#include <stdio.h>
#include <stdlib.h>
#define INFINITY 999

void floydWarshall(int graph[20][20], int n)
{
	int i, j, k;
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
}

int main()
{
	int n, i, j, graph[20][20];
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INFINITY;
		}
	}
	printf("Enter the edges: \n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i != j)
			{
				printf("[%d][%d]: ", i, j);
				scanf("%d", &graph[i][j]);
			}
		}
	}
	printf("The original graph is:\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	floydWarshall(graph, n);
	printf("The shortest path matrix(Cost Matrix) is:\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	return 0;
}
