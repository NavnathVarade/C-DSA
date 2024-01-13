// Program to create the doubly linked list with its all operation.
#include <stdio.h>
#include <stdlib.h>
#include "doubly.h"

int main() {
    int choice;

    do {
        printf("\n-------Menu-------\n");
        printf("1. Create a Doubly Linked List.\n");
        printf("2. Display a Doubly Linked List.\n");
        printf("3. Insert a Node at Beginning.\n");
        printf("4. Insert a Node at Position.\n");
        printf("5. Insert a Node at End.\n");
        printf("6. Delete a Node at Beginning.\n");
        printf("7. Delete a Node at Position.\n");
        printf("8. Delete a Node at End.\n");
        printf("9. Search a Node in Doubly Linked List.\n");
        printf("10. Exit.\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n-----Create a Doubly Linked List-----");
                createList();
                break;
            case 2:
                printf("\nData entered in the list:\n");
                displayList();
                break;
            case 3:
                insertAtFront();
                break;
            case 4:
                insertAtPosition();
                break;
            case 5:
                insertAtEnd();
                break;
            case 6:
                deleteAtFront();
                break;
            case 7:
                deleteAtPos();
                break;
            case 8:
                deleteAtEnd();
                break;
            case 9:
                search();
                break;
            case 10:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice\n");
        }
    } while (choice != 10);

    return 0;
}
