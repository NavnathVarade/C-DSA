/*Program to Create and Display a Linked List*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *newnode, *temp;

void createList() {
    int n, i;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));

        if (newnode == NULL) {
            printf("Memory allocation failed. Exiting.");
            exit(1);
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void displayList() {
    int cnt = 0;
    temp = head;

    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
        cnt++;
    }

    printf("\nNumber of nodes: %d\n", cnt);
}

int main() {
    printf("Linked List: Create and display a singly linked list\n");
    createList();
    printf("\nData entered in the list:\n");
    displayList();

    return 0;
}
