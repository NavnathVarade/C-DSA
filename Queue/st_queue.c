/*
Implement a linear queue library (st_queue.h) of integers using a static implementation
of the queue and implementing the above six operations. Write a program that includes queue
library and calls different queueoperations
*/

#include <stdio.h>
#include <stdlib.h>
#include "st_queue.h"
#define MAX 10

void main()
{
    struct queue q;
    int ch, x, n, e;
    initq(&q);
    do
    {
        printf("\n-----Static Implementation of Queue-----\n");
        printf("\n1.Add Element in Queue.");
        printf("\n2.Delete Element from Queue.");
        printf("\n3.Peek Element of Queue.");
        printf("\n4.Is Queue Empty.");
        printf("\n5.IS Queue Full.");
        printf("\n6.Exit.");
        printf("\nEnter Your Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter Element to be Inserted in Queue : ");
            scanf("%d", &x);
            addq(&q, x);
            break;
        case 2:
            e = delq(&q);
            if (e != 0)
                printf("\nDeleted Element is : %d", e);
            else
                printf("\nQueue is Empty.");
            break;
        case 3:
            e = peekq(&q);
            if (e == 1)
                printf("\nList is Empty.");
            else
                printf("\nElement at Front of Queue is : %d", e);
            break;
        case 4:
            e = isemptyq(&q);
            if (e == 1)
                printf("\nList is Empty.");
            else
                printf("\nList is not Empty.");
            break;
        case 5:
            e = isfullq(&q);
            if (e == 1)
                printf("\nList is Full.");
            else
                printf("\nList is not Full.");
            break;
        case 6:
            exit(0);
            break;
        }
    } while (ch != 6);
}