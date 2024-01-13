/* Deletion on singly circular Linked List */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *last = NULL, *newnode, *temp, *head = NULL;

// Function prototypes
void createList();
void displayList();
struct node *deleteAtFront();
struct node *deleteAtEnd();
struct node *deleteAtPos();

int main()
{
    int choice;

    printf("Linked List: Delete elements from a singly circular linked list\n");
    createList();
    printf("\nData entered in the list:\n");
    displayList();

    do
    {
        printf("\n**** Deletion on Singly Circular Linked List ****\n");
        printf("1. Delete from Front\n");
        printf("2. Delete from End\n");
        printf("3. Delete from Given Position\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            deleteAtFront();
            break;
        case 2:
            deleteAtEnd();
            break;
        case 3:
            deleteAtPos();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

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
        printf(" %d \t", temp->data); // prints the data of current node
        temp = temp->next;            // advances the position of current node
        cnt++;
    }
    printf("\n Number of nodes are : %d\n", cnt);
}

struct node *deleteAtFront()
{
    struct node *temp = NULL;
    printf("\nDeleted Element is : %d\n", head->data);
    if (head->next == NULL)
    {
        free(head);
        head = last = NULL;
    }
    else
    {
        temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
    }
    displayList();
}

struct node *deleteAtEnd()
{
    struct node *temp = NULL;
    if (head->next == NULL)
    {
        free(head);
        head = last = NULL;
    }
    else
    {
        last = head;
        while (last->next != NULL)
        {
            temp = last; // temp is the pointer element pointing to previous element to be deleted
            last = last->next;
        }
        temp->next = NULL;
        printf("\nDeleted Element is : %d\n", last->data);
        free(last);
    }
    printf("\nUpdated List is : ");
    displayList();
}

struct node *deleteAtPos()
{
    int i, pos;
    struct node *prev = NULL, *temp = head;
    printf("\nEnter the Position Whose Element is to be deleted : ");
    scanf("%d", &pos);
    for (i = 1; i < pos - 1; i++)
        temp = temp->next;
    prev = temp->next;
    temp->next = prev->next;
    prev->next = NULL;
    printf("\nDeleted Element is = %d", prev->data);
    free(prev);
    printf("\n Updated List is : ");
    displayList();
}
