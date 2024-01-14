/*
Write a program that reverses a string of characters. The function should use a stack library
(cststack.h) of stack of characters using a static implementation of the stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include "cststack.h"

void main()
{
    char str[MAX];
    int i;

    printf("\nInput a String: ");
    gets(str);

    for (i = 0; i < strlen(str); i++)
        pushChar(str[i]);

    for (i = 0; i < strlen(str); i++)
        str[i] = popChar();

    printf("Reversed String is: %s\n", str);
}
