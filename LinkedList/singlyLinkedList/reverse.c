#include <stdio.h>
#include <stdlib.h>
#include "reverse.h"

int main()
{
    int n, choice;
    do
    {
        printf("\n\n****MENU****\n");
        printf("1. Create a Linked List.\n");
        printf("2. Display a Linked List.\n");
        printf("3. Reverse a Linked List..\n");
        printf("4. Quit.");
        printf("\n Enter choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Linked List : To Reverse a Linked List :\n");
            createList();
            break;
        case 2:
            printf("\n Data entered in the list : \n");
            displayList();
            break;
        case 3:
            reverse();
            break;
        case 4:
            exit(0);
            break;
        }
    } while (choice != 4);
    return 0;
}