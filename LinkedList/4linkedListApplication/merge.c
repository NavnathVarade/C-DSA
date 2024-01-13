/*
Write a program that merges two ordered linked lists into third new list. When two lists are
merged the data in the resulting list are also ordered. The two original lists should be left
unchanged. That is merged list should be new one. Use linked implementation.
*/

#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node* next;
};

struct node *newnode = NULL, *last = NULL, *head1 = NULL, *head2 = NULL, *head3 = NULL, *head = NULL, *temp, *current;

// Function to create a sorted linked list
struct node *createList(struct node *head)
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

        // Inserting the new node in a sorted order
        if (head == NULL || head->data >= newnode->data)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            current = head;
            while (current->next != NULL && current->next->data < newnode->data)
            {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
    }
    return head;
} 

// Function to display the linked list
void displayList(struct node *head)
{
    temp = head;
    while (temp != NULL)
    {
        printf(" %d \t", temp->data);
        temp = temp->next;
    }
}

// Function to merge two sorted linked lists into a new list
void merge(struct node *head1, struct node *head2)
{
    if (head1->data < head2->data)
    {
        head3 = last = head1;
        head1 = head1->next;
        last->next = NULL;
    }
    else
    {
        head3 = last = head2;
        head2 = head2->next;
        last->next = NULL;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            last->next = head1;
            last = head1;
            head1 = head1->next;
            last->next = NULL;
        }
        else
        {
            last->next = head2;
            last = head2;
            head2 = head2->next;
            last->next = NULL;
        }
    }

    if (head1 != NULL)
        last->next = head1;
    else
        last->next = head2;
}

int main()
{
    int n;

    // Creating the first linked list
    printf("\nCreate First Linked List : \n");
    head1 = createList(head1);
    printf("\n First Linked List is : \n");
    displayList(head1);

    // Creating the second linked list
    printf("\nCreate Second Linked List : \n");
    head2 = createList(head2);
    printf("\n Second Linked List is : \n");
    displayList(head2);

    // Merging the two linked lists
    printf("\n Merged Linked List is : \n");
    merge(head1, head2);
    displayList(head3);

    return 0;
}
