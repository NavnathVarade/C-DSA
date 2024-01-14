/*
Write a program that checks whether a string of characters is palindrome or not. The
function should use a stack library (cststack.h) of stack of characters using a static
implementation of the stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"

void main()
{
    int i, choice;
    char s[MAX], b;
    while (1)
    {
        printf("\n1:Enter a String.");
        printf("\n2:Exit.\n");
        printf("Enter your Choice : \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the String You Want : \n");
            scanf("%s", s);
            for (i = 0; s[i] != '\0'; i++)
            {
                b = s[i];
                push(b);
            }
            for (i = 0; i < (strlen(s) / 2); i++)
            {
                if (stack[top] == stack[front])
                {
                    pop();
                    front++;
                }
                else
                {
                    printf("%s is not a palindrome\n", s);
                    break;
                }
            }
            if ((strlen(s) / 2) == front)
                printf("%s is palindrome\n", s);
            front = 0;
            top = -1;
            break;
        case 2:
            exit(0);
        default:
            printf("enter correct choice\n");
        }
    }
}