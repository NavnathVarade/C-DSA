/*
Implement a linear queue library (dyqueue.h) of integers using a dynamic (singly linked
list) implementation of the queue and implementing the above five operations. Write a driver
program that includes queue library and calls different queue operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include "dy_queue.h"

void main()
{
    int i, n, ch, value;
    printf("\nDynamic Implementation of Queue using Linked List\n");
    do
    {
        printf("\n1.Insert Element in Queue(Enqueue).");
        printf("\n2.Delete Element from Queue(Dequeue).");
        printf("\n3.Display Elements of Queue.");
        printf("\n4.Peek Element of Queue.");
        printf("\n5.Exit.");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter number of elements you wnat to insert in Queue : ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("\nEnter the Element to be Inserted : ");
                scanf("%d", &value);
                enqueue(value);
            }
            break;
        case 2:
            printf("Deleted Element is :%d\n", dequeue());
            printf("\nElements of Queue after Deletion are : ");
            display();
            break;
        case 3:
            printf("\nThe Elements of Queue are :  \n");
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nInvalid Choice\n");
        }
    } while (ch != 5);
}