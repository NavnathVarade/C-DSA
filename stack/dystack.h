#include <stdio.h>
#include <stdlib.h>

// Node structure for a stack element
struct node
{
    int data;          // Data of the node
    struct node *next; // Pointer to the next node
} *top;                // Pointer to the top of the stack

// Function to initialize the stack
void initialize()
{
    top = NULL; // Set the top pointer to NULL, indicating an empty stack
}

// Function to check if the stack is empty
int isEmpty()
{
    if (top == NULL)
        return 1; // Return 1 if the stack is empty
    else
        return 0; // Return 0 if the stack is not empty
}

// Function to peek (retrieve without removing) the top element of the stack
int peek()
{
    return top->data; // Return the data of the top element
}

// Function to push an element onto the stack
void push(int num)
{
    struct node *newnode;                                     // Create a new node
    newnode = (struct node *)malloc(1 * sizeof(struct node)); // Allocate memory for the new node
    newnode->data = num;                                      // Set the data of the new node
    newnode->next = NULL;                                     // Initialize the next pointer of the new node

    if (top == NULL)
    {
        top = newnode; // If the stack is empty, set the top to the new node
        top->next = NULL;
    }
    else
    {
        newnode->next = top; // If the stack is not empty, link the new node to the current top
        top = newnode;       // Update the top to the new node
    }
}

// Function to pop (remove) the top element from the stack
void pop()
{
    struct node *temp;

    if (isEmpty())
    {
        printf("\nStack is Empty.\n"); // Display an error message if the stack is empty
        return;
    }
    else
    {
        temp = top;                                       // Save the current top node
        top = top->next;                                  // Move the top pointer to the next node
        printf("\nPopped Element is : %d\n", temp->data); // Display the popped element
        free(temp);                                       // Free the memory of the removed node
    }
}

// Function to display the elements of the stack
void display(struct node *temp)
{
    while (temp != NULL)
    {
        printf("%d", temp->data); // Display the data of the current node

        temp = temp->next; // Move to the next node

        if (temp != NULL)
            printf("-->"); // Display arrow if there are more elements
    }
    printf("\n");
}

// Driver program can be added here
