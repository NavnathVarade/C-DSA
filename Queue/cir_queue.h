/*
Implement a circular queue library (cir_queue.h) of integers using a dynamic (circular
linked list) implementation of the queue and implementing the above five operations. Write a
menu driven program that includes queue library and calls different queue operations.
*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int d) // Insert elements in Queue
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = d;
    newnode->next = NULL;
    if ((rear == NULL) && (front == NULL))
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        newnode->next = front;
    }
}

void dequeue() // Delete an element from Queue
{
    struct node *temp;
    temp = front;
    printf("\nDeleted Element is %d", temp->data);
    if ((front == NULL) && (rear == NULL))
        printf("\nQueue is Empty");
    else if (front == rear)
    {
        front = rear = NULL;
        free(temp);
    }
    else
    {
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display()
{ // Print the elements of Queue
    struct node *temp;
    temp = front;
    if ((front == NULL) && (rear == NULL))
        printf("\nQueue is Empty");
    else
    {
        do
        {
            printf(" %d\t", temp->data);
            temp = temp->next;
        } while (temp != front);
    }
}

void peek()
{
    if ((front == NULL) && (rear == NULL))
        printf("\nQueue is empty");
    else
        printf("\nThe front element is %d", front->data);
}
