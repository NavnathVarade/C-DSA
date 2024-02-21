/*
Write a C program that accepts the vertices and edges of a graph and store it as an adjacency list. Implement function to
traverse the graph using Breadth First Search (BFS) traversal.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct node
{
    int vertex;
    struct node *next;
} *v[10];

typedef struct Q
{
    int data[MAX];
    int R, F;
} Q;

int empty(Q *P)
{
    if (P->R == -1)
        return (1);
    return (0);
}

int full(Q *P)
{
    if (P->R == MAX - 1)
        return (1);
    return (0);
}

void enqueue(Q *P, int x)
{
    if (P->R == -1)
    {
        P->R = P->F = 0;
        P->data[P->R] = x;
    }
    else
    {
        P->R = P->R + 1;
        P->data[P->R] = x;
    }
}

int dequeue(Q *P)
{
    int x;
    x = P->data[P->F];
    if (P->R == P->F)
    {
        P->R = -1;
        P->F = -1;
    }
    else
        P->F = P->F + 1;
    return (x);
}

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
    struct node *temp;
    int i;
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
}

void BFS(int start)
{
    int n, w, i, visited[MAX];
    Q q;
    struct node *temp;
    q.R = q.F = -1;
    // initialise
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    enqueue(&q, start);
    printf("\n%d", start);
    visited[start] = 1;
    while (!empty(&q))
    {
        start = dequeue(&q);
        // insert all unvisited,adjacent vertices of v into queue
        for (temp = v[start]; temp != NULL; temp = temp->next)
        {
            w = temp->vertex;
            if (visited[w] == 0)
            {
                enqueue(&q, w);
                visited[w] = 1;
                printf("\t%d", w);
            }
        }
    }
}

void main()
{
    int m[10][10], n, start;
    printf("\nEnter Number of Vertices : ");
    scanf("%d", &n);
    create(m, n);
    createlist(m, n);
    display(n);
    printf("\nEnter the starting vertext for BFS Traversal : ");
    scanf("%d", &start);
    printf("\nBFS Traversal is : ");
    BFS(start);
}