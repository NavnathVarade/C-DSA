/*
Write a C program that accepts the vertices and edges of a graph. Create adjacency list.Implement functions to print indegree, outdegree and total degree of all vertex of graph.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node *next;
} *v[10];

void create(int m[10][10], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            m[i][j] = 0;
            if (i != j)
            {
                printf("\nIs there an edge between %d and %d : ", i + 1, j + 1);
                scanf("%d", &m[i][j]);
            }
        }
    }
}

void createlist(int m[10][10], int n)
{
    int i, j;
    struct node *temp, *newnode;
    for (i = 0; i < n; i++)
    {
        v[i] = NULL;
        for (j = 0; j < n; j++)
        {
            if (m[i][j] == 1)
            {
                newnode = (struct node *)malloc(sizeof(struct node));
                newnode->next = NULL;
                newnode->vertex = j + 1;
                if (v[i] == NULL)
                    v[i] = temp = newnode;
                else
                {
                    temp->next = newnode;
                    temp = newnode;
                }
            }
        }
    }
}

void display(int n)
{
    struct node *temp, *p;
    int i, j, in_deg, out_deg;
    printf("\n-----Adjacency List-----\n");
    for (i = 0; i < n; i++)
    {
        printf("\nv%d | ", i + 1);
        temp = v[i];
        while (temp)
        {
            printf("v%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL");
    }
    printf("\n Vertex \t In_Degree \t Out_Degree \t Total_Degree ");
    for (i = 0; i < n; i++)
    {
        in_deg = out_deg = 0;
        p = v[i];
        while (p != NULL)
        {
            out_deg++;
            p = p->next;
        }
        for (j = 0; j < n; j++)
        {
            p = v[j];
            while (p != NULL)
            {
                if (p->vertex == i + 1)
                    in_deg++;
                p = p->next;
            }
        }
        printf("\n\n %5d\t\t\t%d\t\t%d\t\t%d\n\n", i + 1, in_deg, out_deg, in_deg + out_deg);
    }
}

void main()
{
    int m[10][10], n;
    printf("\nEnter Number of Vertices : ");
    scanf("%d", &n);
    create(m, n);
    createlist(m, n);
    display(n);
}