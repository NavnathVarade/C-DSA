/*
Write a program to convert an infix expressionof the form (a*(b+c)*((d-a)/b)) intoits
equivalent postfix notation. Consider usual precedence’s of operators. Use stack library of
stack of characters using static implementation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "infix.h"

void main()
{
    struct stack s1;
    char exp[20], x;
    int i;
    init(&s1);
    printf("\nEnter the Infix Expression : ");
    scanf("%s", exp);
    i = 0;
    while (exp[i] != '\0')
    {
        if (isalnum(exp[i]))
            printf("%c", exp[i]);
        else if (exp[i] == '(')
            push(&s1, exp[i]);
        else if (exp[i] == ')')
        {
            while ((x = pop(&s1)) != '(')
                printf("%c", x);
        }
        else
        {
            while (priority(s1.data[s1.top]) >= priority(exp[i]))
                printf("%c", pop(&s1));
            push(&s1, exp[i]);
        }
        i++;
    }
    while (!isempty(&s1))
        printf("%c", pop(&s1));
}