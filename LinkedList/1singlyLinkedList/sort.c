/*There are lists where insertion should ensure the ordering of data elements. Since the
elements are in ascending order the search can terminate once equal or greater element is
found. Implement a singly linked list of ordered integers(ascending/descending) with insert,
search and display operations.*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node
{
    int data;
    struct node* next;
};

// Declare global pointers for the head, newnode, temp, and current nodes
struct node *head = NULL, *newnode, *temp, *current;

// Function to create a singly linked list of ordered integers in ascending order
void createList()
{
    int n, i;
    printf("\nInput the number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        // Allocate memory for a new node
        newnode = (struct node *)malloc(sizeof(struct node));

        // Input data for the new node
        printf("\nInput data for node %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        // Insert the new node at the correct position to maintain ascending order
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
}

// Function to search for an element in the linked list
void search()
{
    struct node *ptr;
    int element, i = 0, flag = 0;
    ptr = head;

    if (ptr == NULL)
    {
        printf("\nLinked List is Empty.\n");
    }
    else
    {
        // Input the element to be searched
        printf("\nEnter the element to be searched: ");
        scanf("%d", &element);

        // Traverse the linked list to find the element
        while (ptr != NULL)
        {
            if (ptr->data == element)
            {
                printf("\nElement %d is found at location %d.\n", element, i + 1);
                flag = 1;
                break;
            }
            i++;
            ptr = ptr->next;
        }

        // Display a message if the element is not found
        if (flag == 0)
        {
            printf("\nElement not found in the Linked List.\n");
        }
    }
}

// Function to display the linked list
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

    printf("\nNumber of nodes: %d\n", cnt);
}

// Main function
int main()
{
    printf("\nLinked List: Create, Display, and Search in Singly Linked List:\n");

    // Call the function to create the linked list
    createList();

    // Display the data entered in the list
    printf("\nData entered in the list:\n");
    displayList();

    // Perform a search operation
    search();

    return 0;
}
