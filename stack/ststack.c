#include <stdio.h>
#include <stdlib.h>
#include "ststack.h" // Assuming ststack.h contains the necessary declarations and definitions for stack operations.

void main()
{
    struct stack s; // Declare a stack using the 'struct stack' structure.
    int ch, x, n, e, i;
    init(&s); // Initialize the stack.

    printf("\n-----Static Implementation of Stack -----");
    do
    {
        printf("\n1. Push Data into the Stack.");
        printf("\n2. Pop Data from the Stack.");
        printf("\n3. Peek (Top) Element of the Stack.");
        printf("\n4. Is Stack Empty.");
        printf("\n5. Is Stack Full.");
        printf("\n6. Display Stack.");
        printf("\n7. Exit.");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the Number of Elements to be Pushed: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("\nEnter the Element to be Pushed: ");
                scanf("%d", &x);
                push(&s, x); // Call the push function to insert an element into the stack.
            }
            break;
        case 2:
            e = pop(&s); // Call the pop function to remove an element from the stack.
            if (e != 0)
                printf("\nDeleted Element is: %d", e);
            else
                printf("\nStack is Empty.");
            break;
        case 3:
            e = peek(&s); // Call the peek function to get the top element of the stack.
            printf("\nElement on Top of Stack is: %d", e);
            break;
        case 4:
            e = isempty(&s); // Call the isempty function to check if the stack is empty.
            if (e == 1)
                printf("\nStack is Empty.");
            else
                printf("\nStack is Not Empty.");
            break;
        case 5:
            e = isfull(&s); // Call the isfull function to check if the stack is full.
            if (e == 1)
                printf("\nStack is Full.");
            else
                printf("\nStack is Not Full.");
            break;
        case 6:
            display(&s); // Call the display function to print the elements of the stack.
            break;
        case 7:
            exit(0); // Exit the program.
            break;
        }
    } while (ch != 7);
}
