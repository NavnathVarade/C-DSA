/*
Write a C program that accepts the vertices and edges of a graph and store it as an
adjacency matrix. Implement function to traverse the graph using Breadth First Search
(BFS) traversal.
*/

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct queue q;
    q.size = 50;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    int i, j, v, n, node, visited[10], a[10][10];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    printf("Enter graph data in matrix form:    \n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter the starting vertex: ");
    scanf("%d", &v);

    printf("\nBFS is : ");
    printf("%d ", v);
    enqueue(&q, v);
    while (!isEmpty(&q))
    {
        int node = dequeue(&q); // remove
        visited[v] = 1;         // mark visited
        for (int j = 1; j <= n; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j); // add to the bfs
                visited[j] = 1;
                enqueue(&q, j); // add neighbors
            }
        }
    }
    
    return 0;
}
