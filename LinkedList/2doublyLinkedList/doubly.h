#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL, *newnode, *temp, *last;

void createList() {
    int n, i;
    printf("\nInput the number of nodes : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nInput data for node %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
            temp->next = NULL;
        }
    }
}

void displayList() {
    int cnt = 0;
    temp = head;

    while (temp != NULL) {
        printf(" %d \t", temp->data);
        temp = temp->next;
        cnt++;
    }

    printf("\n Number of nodes are : %d\n", cnt);
}

void insertAtFront() {
    int data;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the data to be inserted at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->next = newnode->prev = NULL;

    if (head == NULL)
        head = last = newnode;
    else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }

    printf("Updated list is : \n");
    displayList();
}

void insertAtPosition() {
    struct node *newnode;
    int pos, i = 1;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter position and data to be inserted:");
    scanf("%d %d", &pos, &newnode->data);
    newnode->next = newnode->prev = NULL;
    temp = head;

    if (pos == 1) {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    } else {
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }

        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }

    printf("Updated list is : \n");
    displayList();
}

void insertAtEnd() {
    struct node *newnode, *last;
    last = head;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the data to be inserted at the end: ");
    scanf("%d", &newnode->data);
    newnode->next = newnode->prev = NULL;

    if (head == NULL)
        head = last = newnode;
    else {
        while (last->next != NULL) {
            last = last->next;
        }

        last->next = newnode;
        newnode->prev = last;
        last = newnode;
    }

    printf("Updated list is : \n");
    displayList();
}

void deleteAtFront() {
    struct node *temp = NULL;
    printf("\nDeleted Element is : %d\n", head->data);

    if (head->next == NULL) {
        free(head);
        head = last = NULL;
    } else {
        temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        free(temp);
    }

    displayList();
}

void deleteAtPos() {
    int i, pos;
    struct node *prev = NULL, *ptr;
    printf("\nEnter the Position Whose Element is to be deleted : ");
    scanf("%d", &pos);

    temp = head;

    for (i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    ptr = temp->next;
    temp->next = ptr->next;
    ptr->next->prev = temp;
    ptr->next = ptr->prev = NULL;

    printf("\nDeleted Element is = %d", ptr->data);
    free(ptr);

    printf("\nUpdated List is : ");
    displayList();
}

void deleteAtEnd() {
    struct node *temp = NULL;

    if (head->next == NULL) {
        free(head);
        head = last = NULL;
    } else {
        last = head;

        while (last->next != NULL) {
            last = last->next;
        }

        temp = last->prev;
        temp->next = NULL;

        printf("\nDeleted Element is : %d\n", last->data);
        free(last);
        last = temp;
    }

    printf("\nUpdated List is : ");
    displayList();
}

void search() {
    struct node *ptr;
    int element, i = 0, flag = 0;
    ptr = head;

    if (ptr == NULL)
        printf("\nLinked List is Empty.");
    else {
        printf("\nEnter the Element to be Searched : ");
        scanf("%d", &element);

        while (ptr != NULL) {
            if (ptr->data == element) {
                printf("\nElement %d is found at location %d\n", element, i + 1);
                flag = 1;
                break;
            }
            i++;
            ptr = ptr->next;
        }

        if (flag == 0)
            printf("\nElement not found in the Linked List.");
    }
}