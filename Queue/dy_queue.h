#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if ((front == NULL) && (rear == NULL))
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

int dequeue()
{
    if (front == NULL)
    {
        printf("\nQueue is Empty.\n");
        return 0;
    }
    else
    {
        struct node *temp = front;
        int temp_data = front->data;
        front = front->next;
        free(temp);
        return temp_data;
    }
}

void display()
{
    struct node *temp;
    if ((front == NULL) && (rear == NULL))
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        temp = front;
        while (temp)
        {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n\n");
    }
}

void peek()
{
    if ((front == NULL) && (rear == NULL))
        printf("\nQueue is empty");
    else
        printf("\nThe front(peek) element is %d", front->data);
}