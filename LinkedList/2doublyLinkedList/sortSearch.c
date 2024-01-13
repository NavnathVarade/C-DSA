/*
There are lists where insertion should ensure the ordering of data elements. Since the
elements are in ascending order the search can terminate once equal or greater element is
found. Implement a doubly linked list of ordered integers(ascending/descending) with insert,
search and display operations.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL, *newnode, *temp, *last, *current;

void createList()
{
    int n, i;
    printf("\nInput the number of nodes : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nInput data for node %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;

        if (head == NULL)
            head = newnode;
        else if (head->data >= newnode->data)
        {
            newnode->next = head;
            newnode->next->prev = newnode;
            head = newnode;
        }
        else
        {
            current = head;
            while (current->next != NULL && current->next->data < newnode->data)
                current = current->next;

            newnode->next = current->next;
            if (current->next != NULL)
                newnode->next->prev = newnode;

            current->next = newnode;
            newnode->prev = current;
        }
    }
}

void displayList()
{
    int cnt = 0;
    temp = head;

    while (temp != NULL)
    {
        printf(" %d \t", temp->data);
        temp = temp->next;
        cnt++;
    }

    printf("\nNumber of nodes are : %d\n", cnt);
}

void search()
{
    struct node *ptr;
    int element, i = 0, flag = 0;
    ptr = head;

    if (ptr == NULL)
        printf("\nLinked List is Empty.\n");
    else
    {
        printf("\nEnter the Element to be Searched : ");
        scanf("%d", &element);

        while (ptr != NULL)
        {
            if (ptr->data == element)
            {
                printf("\nElement %d is found at location %d\n", element, i + 1);
                flag = 1;
                break;
            }
            i++;
            ptr = ptr->next;
        }

        if (flag == 0)
            printf("\nElement not found in the Linked List.\n");
    }
}

int main()
{
    int n;
    printf("\nDoubly Linked List :\n");
    createList();
    printf("\nData entered in the list:\n");
    displayList();
    search();
    return 0;
}
