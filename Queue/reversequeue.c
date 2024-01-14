/*
Write a program to reverse the elements of a queue using queue library.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue
{
    int items[MAX_SIZE];
    int front;
    int rear;
};

void enqueue(struct Queue *q, int item)
{
    if (q->rear == MAX_SIZE - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = item;
}

int dequeue(struct Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is Empty.\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    return item;
}

void display(struct Queue *q)
{
    int i;
    if (q->rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    for (i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

void reverse(struct Queue *q)
{
    if (q->front == -1)
    {
        return;
    }
    int item = dequeue(q);
    reverse(q);
    enqueue(q, item);
}

void main()
{
    int n, x, i;
    struct Queue q;
    q.front = -1;
    q.rear = -1;
    printf("\nEnter Number of Elements in Queue : ");
    scanf("%d", &n);
    printf("\nEnter %d Elements in Queue : ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(&q, x);
    }
    printf("\nQueue Elements before reversing:\n");
    display(&q);
    reverse(&q);
    printf("\nQueue Elements after reversing:\n");
    display(&q);
}