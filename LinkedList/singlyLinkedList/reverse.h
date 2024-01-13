#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *newnode, *temp;
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
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
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
    printf("\n Number of nodes are : %d\n", cnt);
}

void reverse()
{
    struct node *prevnode, *currentnode, *nextnode;
    prevnode = 0;
    currentnode = nextnode = head;
    while (nextnode != 0)
    {
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
    printf("\nReverse Linked List is : ");
    displayList();
}