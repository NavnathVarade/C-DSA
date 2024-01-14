#include <stdio.h>
#include <stdlib.h>
#include "cir_queue.h"
void main()
{
    int ch, n, x, i;
    do
    {
        printf("\n----- Dynamic Implementation of Circular Queue ----- ");
        printf("\n1.Insert Element in Circular Queue.");
        printf("\n2.Display Elements of Circular Queue.");
        printf("\n3.Delete Element from Circular Queue.");
        printf("\n4.Peek Element of Circular Queue.");
        printf("\n5.Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter Number of Elements to be entered in Queue : ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("\nEnter Element to insert in Queue : ");
                scanf("%d", &x);
                enqueue(x);
            }
            break;

        case 2:
            printf("\nElements of Circular Queue are : \n");
            display();
            printf("\n");
            break;

        case 3:
            dequeue();
            printf("\nElements of Circular Queue After Deletion are : ");
            display();
            break;

        case 4:
            peek();
            break;

        case 5:
            exit(0);
            break;
        }
    } while (ch != 5);
}