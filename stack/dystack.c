/*
Implement a stack library (dystack.h) of integers using a dynamic (linked list)
implementation of the stack and implementing the above five operations. Write a driver
program that includes stack library and calls different stack operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include "dystack.h"

void main()
{
    int i, x, n, ch, e;
    initialize();

    printf("\n -----Dynamic Implementation of Stack -----\n");
    do
    {
        printf("\n1.Push Data into the Stack.");
        printf("\n2.Pop Data from the Stack.");
        printf("\n3.Peek(Top) Element of the Stack.");
        printf("\n4.Is Stack Empty.");
        printf("\n5.Display Stack.");
        printf("\n6.Exit.");
        printf("\nEnter Your Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the Number of Elements to be Pushed : ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("\nEnter the Element to be Pushed : ");
                scanf("%d", &x);
                push(x);
            }
            break;
        case 2:
            pop();
            printf("\nUpdated Stack is : \n");
            display(top);
            break;
        case 3:
            printf("\nTop Element of Stack is : %d", peek());
            break;
        case 4:
            e = isEmpty();
            if (e == 1)
                printf("\nStack is Empty.");
            else
                printf("\nStack is Not Empty.");
            break;
        case 5:
            printf("\nElements of Stack are : \n");
            display(top);
            break;
        case 6:
            exit(0);
            break;
        }
    } while (ch != 6);
}