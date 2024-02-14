/*Write a C program that accepts the vertices and edges of a graph and stores it as an adjacency matrix. Display the adjacency matrix.*/

#include <stdio.h>
#include <stdlib.h>
void main()
{
	int option;
	int dir_graph();
	int undir_graph();
	do
	{
		printf("\n A Program to represent a Graph by using an");
		printf("Adjacency Matrix method \n");
		printf("\n 1. Directed Graph ");
		printf("\n 2. Un-Directed Graph ");
		printf("\n 3. Exit ");
		printf("\n\n Select a proper option : ");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			dir_graph();
			break;
		case 2:
			undir_graph();
			break;
		case 3:
			exit(0);
		}
	} while (option != 3);
}

int dir_graph()
{
	int adj_mat[50][50];
	int n;
	int in_deg, out_deg, i, j;
	printf("\n How Many Vertices ? : ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("\nIs the edge present between %d & %d(1,0) : ", i + 1, j + 1);
			scanf("%d", &adj_mat[i][j]);
		}
	}

	printf("\nAdjacency matrix Of Directed Graph is:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%5d", adj_mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int undir_graph()
{
	int adj_mat[50][50];
	int deg, i, j, n;
	printf("\n How Many Vertices ? : ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{

			printf("\nIs the edge present between %d & %d(1,0) : ", i + 1, j + 1);
			scanf("%d", &adj_mat[i][j]);
		}
	}

	printf("\nAdjacency matrix Of Un-Directed Graph is:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%5d", adj_mat[i][j]);
		}
		printf("\n");
	}

	return 0;
}
