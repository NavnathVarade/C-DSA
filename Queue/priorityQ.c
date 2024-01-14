/*
Implement a priority queue library (PriorityQ.h) of integers using a static implementation
of the queue and implementing the below two operations. Write a driver program that
includes queue library and calls different queue operations.
1) Add an element with its priorityinto the queue.
2) Delete an element from queue according to its priority.
*/

#include <stdio.h>
#include <stdlib.h>
#include "priorityQ.h"

#define MAX 5

int pri_que[MAX];
int front, rear;

void main()
{
    int n, ch, x, i;
    init();
    do
    {
        printf("\n1. Insert Elements into the Queue");
        printf("\n2. Delete an element from the Queue");
        printf("\n3. Display queue elements");
        printf("\n4. Is Queue Empty.");
        printf("\n5. Is Queue Full.");
        printf("\n6. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter number of elements you want to insert in Queue : ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("\nEnter value to be inserted : ");
                scanf("%d", &x);
                insert_by_priority(x);
            }
            break;
        case 2:
            printf("\nEnter value to delete : ");
            scanf("%d", &n);
            delete_by_priority(n);
            break;
        case 3:
            display_pqueue();
            break;
        case 4:
            isempty();
            break;
        case 5:
            isfull();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nChoice is incorrect, Enter a correct choice");
        }
    } while (ch != 6);
}