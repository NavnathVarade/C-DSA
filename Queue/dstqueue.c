/*
A doubly ended queue allows additions and deletions from both the ends that is front and
rear. Initially additions from the front will not be possible. To avoid this situation, the array
can be treated as if it were circular. Implement a queue library (dstqueue.h) of integers using
a static implementation of the circular queue and implementing the nine operations :
1)init(Q),
2) isempty(Q) 3) isFull(Q) 4)getFront(Q), 5)getRear(Q), 6)addFront(Q,x),
7)deleteFront(Q)
8) addRear(Q,x)
9)deleteRear(Q) .
*/

#include <stdio.h>
#include <stdlib.h>
#include "dstqueue.h"

#define size 5

void main()
{
    int ch, n;
    printf("\n-----Implementation of Double Ended Queue-----\n");
    do
    {
        printf("\n1. Insert at Front.");
        printf("\n2. Insert at Rear.");
        printf("\n3. Delete from Front.");
        printf("\n4. Delete from Rear.");
        printf("\n5. Display Front.");
        printf("\n6. Display Rear.");
        printf("\n7. Display DeQueue.");
        printf("\n8. Is DeQueue Full.");
        printf("\n9. Is DeQueue Empty.");
        printf("\n10. Exit.");
        printf("\nEnter Your Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter Value to be inserted at Front : \n");
            scanf("%d", &n);
            insert_front(n);
            break;
        case 2:
            printf("\nEnter Value to be inserted at Rear : \n");
            scanf("%d", &n);
            insert_rear(n);
            break;
        case 3:
            delete_front();
            display();
            break;
        case 4:
            delete_rear();
            display();
            break;
        case 5:
            getfront();
            break;
        case 6:
            getrear();
            break;
        case 7:
            printf("\nElements of DeQueue are : \n");
            display();
            break;
        case 8:
            isfull();
            break;
        case 9:
            isempty();
            break;
        case 10:
            exit(0);
            break;
        }
    } while (ch != 10);
}