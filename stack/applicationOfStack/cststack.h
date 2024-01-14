#include <stdio.h>
#include <string.h>

#define MAX 10

/*stack variables*/
int top = -1;
int item;

/*string declaration*/
char stack_string[MAX];
void pushChar(char item);
char popChar();
int isEmpty();
int isFull();

void pushChar(char item)
{
    if (isFull())
    {
        printf("\nStack is FULL !!!\n");
        return;
    }

    /*increase top and push item in stack*/
    top = top + 1;
    stack_string[top] = item;
}

char popChar()
{
    if (isEmpty())
    {
        printf("\nStack is EMPTY!!!\n");
        return 0;
    }

    /*pop item and decrease top*/
    item = stack_string[top];
    top = top - 1;
    return item;
}

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