#include <stdio.h>
#include <stdlib.h>
#define MAX 10
struct queue
{
    int a[MAX];
    int f, r;
};

void initq(struct queue *q)
{
    q->f = q->r = -1;
}

int isemptyq(struct queue *q)
{
    if (q->f == q->r)
        return 1;
    else
        return 0;
}

int isfullq(struct queue *q)
{
    if (q->r == MAX - 1)
        return 1;
    else
        return 0;
}

void addq(struct queue *q, int x)
{
    if (isfullq(q))
    {
        printf("\nQueue Overflow.");
        return;
    }
    else
        q->a[++q->r] = x;
}

int delq(struct queue *q)
{
    if (isemptyq(q))
    {
        printf("\nQueue is Empty.");
        return 0;
    }
    else
        return q->a[++q->f];
}

int peekq(struct queue *q)
{
    if (!isemptyq(q))
        return q->a[q->f + 1];
}