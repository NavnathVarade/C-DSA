#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct stack
{
	int a[MAX];
	int top;
} stack;

int init(struct stack *s)
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
		s->a[++s->top] = x;
}

int pop(struct stack *s)
{
	int num;
	if ((isempty(s)) == 1)
		return 0;
	else
	{
		num = s->a[s->top--];
		return num;
	}
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