/*
Write a C program that accepts the vertices and edges of a graph and store it as an
adjacencymatrix. Implement functions to print indegree, outdegree and total degree of
all vertices of graph.
*/

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
			break;
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
			printf("\nIs the edge present between %d & %d(1,0)", i + 1, j + 1);
			scanf("%d", &adj_mat[i][j]);
		}
	}

	printf("\nAdjacency matrix is:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%5d", adj_mat[i][j]);
		}
		printf("\n");
	}

	printf("\n Vertex \t In_Degree \t Out_Degree \t Total_Degree ");
	for (i = 0; i < n; i++)
	{
		in_deg = out_deg = 0;
		for (j = 0; j < n; j++)
		{
			if (adj_mat[j][i] == 1)
				in_deg++;
		}
		for (j = 0; j < n; j++)
			if (adj_mat[i][j] == 1)
				out_deg++;
		printf("\n\n%d\t\t\t%d\t\t%d\t\t%d\n\n", i + 1, in_deg, out_deg, in_deg + out_deg);
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
			printf("\nIs the edge present between %d & %d(1,0)", i + 1, j + 1);
			scanf("%d", &adj_mat[i][j]);
		}
	}

	printf("\nAdjacency matrix is:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%5d", adj_mat[i][j]);
		}
		printf("\n");
	}

	printf("\n Vertex \t Degree ");
	for (i = 0; i < n; i++)
	{
		deg = 0;
		for (j = 0; j < n; j++)
			if (adj_mat[i][j] == 1)
				deg++;
		printf("\n\n %5d \t\t %d\n\n", i + 1, deg);
	}
	
	return 0;
}
