#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int top = -1, front = 0;
int stack[MAX];

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

void push(char a)
{
    if (isFull())
    {
        printf("\nStack is FULL !!!\n");
        return;
    }
    /*increase top and push item in stack*/
    top++;
    stack[top] = a;
}

void pop()
{
    if (isEmpty())
    {
        printf("\nStack is EMPTY!!!\n");
        return;
    }
    /*pop item and decrease top*/
    top--;
}
