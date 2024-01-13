/*
There are lists where new elements are always appended at the end of the list. The list can
be implemented as a circular list with the external pointer pointing to the last element of the
list. Implement doubly linked circular list of integers with append and display operations. The
operation append(L, n), appends to the end of the list, n integers either accepted from user or
randomly generated.
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *tail, *ptr;

void createList()
{
    int i, n;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        printf("Input data for node %d: ", i + 1);
        scanf("%d", &ptr->data);

        if (head == NULL)
        {
            // List is empty, initialize head and tail
            head = tail = ptr;
            head->next = head;
            head->prev = head;
        }
        else
        {
            // Append the node to the end of the circular list
            tail->next = ptr;
            ptr->next = head;
            ptr->prev = tail;
            head->prev = ptr;
            tail = ptr;
        }
    }
}

void append(struct node *ptr)
{
    int n, i;
    printf("\nEnter the number of nodes to be appended: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data to add in the list: ");
        scanf("%d", &ptr->data);

        // Append the new node to the end of the circular list
        ptr->prev = tail;
        ptr->next = head;
        head->prev = ptr;
        tail->next = ptr;
        tail = ptr;
    }
}

void displayList(struct node *ptr)
{
    ptr = head;
    printf("\nElements in the Linked List are: ");
    while (ptr != tail)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}

int main()
{
    printf("\nDoubly Linked List: Create and Display Doubly Circular Linked List\n");
    createList();
    printf("\nData Entered in the Linked List:\n");
    displayList(head);
    append(ptr);
    printf("\nData After Appending in the Linked List:\n");
    displayList(head);

    return 0;
}
