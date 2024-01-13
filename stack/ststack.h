/*
Implement a stack library (ststack.h) of integers using a static implementationof the stack
and implementing the above six operations. Write a driver program that includes stack library
and calls different stack operations.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct stack
{
    int a[MAX];
    int top;
};

void init(struct stack *s)
{
    s->top = -1;
}

int isempty(struct stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int isfull(struct stack *s)
{
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

void push(struct stack *s, int x)
{
    if ((isfull(s)) == 1)
    {
        printf("\nStack Overflow.");
        return;
    }
    else
    {
        s->a[++s->top] = x;
    }
}

int pop(struct stack *s)
{
    if ((isempty(s)) == 1)
        return 0;
    else
        return s->a[s->top--];
}

int peek(struct stack *s)
{
    return s->a[s->top];
}

void display(struct stack *s)
{
    if (s->top == -1)
        printf("\nStack is Empty!!!");
    else
    {
        int i;
        printf("\nStack elements are : \n");
        for (i = s->top; i >= 0; i--)
            printf("%d\n", s->a[i]);
    }
}