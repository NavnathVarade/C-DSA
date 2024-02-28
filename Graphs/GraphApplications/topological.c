/*
Write a C program for the implementation of Topological sorting.
*/

#include <stdio.h>
#include <math.h>

void main()
{
	int i, j, k, m, n, adj_mat[10][10], indeg[10], flag[10], c = 0;
	printf("\nEnter How many Vertices do you want : ");
	scanf("%d", &n);
	printf("ENTER THE ADJACENT MATRIX\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &adj_mat[i][j]);

	for (i = 0; i < n; i++)
	{
		indeg[i] = 0;
		flag[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			indeg[i] = indeg[i] + adj_mat[j][i];
		}
		printf("\nIndegree of Vertex %d is %d", i, indeg[i]);
	}

	printf("\nTHE ENTERED MATRIX IS : \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d", adj_mat[i][j]);
		}
		printf("\n");
	}

	printf("\nTHE TOPOLOGICAL SORT IS : \n");

	while (c <= n)
	{
		for (k = 0; k < n; k++)
		{
			if ((indeg[k] == 0) && (flag[k] == 0))
			{
				printf("%d\t", k + 1);
				flag[k] = 1;
				for (i = 0; i < n; i++)
				{
					if (adj_mat[k][i] == 1)
						adj_mat[k][i] = adj_mat[k][i] - 1;
				}
				for (i = 0; i < n; i++)
				{
					indeg[i] = 0;
				}
				for (m = 0; m < n; m++)
				{
					for (j = 0; j < n; j++)
					{
						indeg[m] = indeg[m] + adj_mat[j][m];
					}
				}
			}
		}
		c++;
	}
}
