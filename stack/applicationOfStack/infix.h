#include <stdio.h>
#include <stdlib.h>

struct stack
{
    char data[20];
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

void push(struct stack *s, char x)
{
    s->top++;
    s->data[s->top] = x;
}

char pop(struct stack *s)
{
    if (s->top == -1)
        return -1;
    else
        return s->data[s->top--];
}

// Finding Precedence of an Opearator
int priority(char x)
{
    if (x == '(')
        return 0;
    else if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '^' || x == '$')
        return 3;
    else
        return -1;
}