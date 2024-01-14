/*
Write a program that copies the contents of one stack into another. Use stack library to
perform basic stack operations. The order of two stacks must be identical.(Hint: Use a
temporary stack to preserve the order).
*/

#include <stdio.h>
#include "stackcopy.h"

int main()
{
    struct stack s1, t, s2;
    init(&s1);
    init(&s2);
    init(&t);
    int i, n, num;
    printf("How many elements in stack1: ");
    scanf("%d", &n);
    printf("Enter element in stack1: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);
        push(&s1, num); // pushing elements in stack1
    }
    while (!isempty(&s1))
    {
        push(&t, pop(&s1)); // pushing stack1 elements in temporary stack
    }
    while (!isempty(&t))
    {
        push(&s1, peek(&t)); // pushing temporary stack element in stack1
        push(&s2, pop(&t));  // pushing temporary stack element in stack2
    }
    display(&s1);
    printf("\n-----Elements of stack1 is copied in stack2------\n");
    display(&s2);
    return 0;
}