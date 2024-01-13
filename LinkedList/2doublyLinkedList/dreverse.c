// Program to reverse the doubly linked list
#include<stdio.h>
#include<stdlib.h>
#include"dreverse.h"

int main()
{
    int n, choice;

    do
    {
        printf("\n\n****MENU****\n");
        printf("1. Create a Linked List.\n");
        printf("2. Display a Linked List.\n");
        printf("3. Reverse a Linked List.\n");
        printf("4. Quit.\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nLinked List: To Reverse a Linked List:\n");
                createList();
                break;
            case 2:
                printf("\nData entered in the list:\n");
                displayList();
                break;
            case 3:
                reverse();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice\n");
        }
    } while(choice != 4);

    return 0;
}
