#include <stdio.h>
#include <stdlib.h>

#define size 5

int deque[size];
int f = -1, r = -1;

void isfull()
{
    if ((f == 0 && r == size - 1) || (f == r + 1))
        printf("\nDeQueue is full.");
    else
        printf("\nDeQueue is not full.");
}

void isempty()
{
    if ((f == -1) && (r == -1))
        printf("\nDeque is empty.");
    else
        printf("\nDeque is not empty.");
}

//  insert_front function will insert the value from the front
void insert_front(int x)
{
    if ((f == 0 && r == size - 1) || (f == r + 1))
    {
        printf("\nDeQueue is full.");
    }
    else if ((f == -1) && (r == -1))
    {
        f = r = 0;
        deque[f] = x;
    }
    else if (f == 0)
    {
        f = size - 1;
        deque[f] = x;
    }
    else
    {
        f = f - 1;
        deque[f] = x;
    }
}

// insert_rear function will insert the value from the rear
void insert_rear(int x)
{
    if ((f == 0 && r == size - 1) || (f == r + 1))
    {
        printf("\nDeQueue is full.");
    }
    else if ((f == -1) && (r == -1))
    {
        r = 0;
        deque[r] = x;
    }
    else if (r == size - 1)
    {
        r = 0;
        deque[r] = x;
    }
    else
    {
        r++;
        deque[r] = x;
    }
}

// display function prints all the value of deque.
void display()
{
    int i = f;
    printf("\nElements in a deque are: ");

    while (i != r)
    {
        printf("%d ", deque[i]);
        i = (i + 1) % size;
    }
    printf("%d", deque[r]);
}

// getfront function retrieves the first value of the deque.
void getfront()
{
    if ((f == -1) && (r == -1))
    {
        printf("\nDeque is empty.");
    }
    else
    {
        printf("\nFront Element of DeQueue is : %d", deque[f]);
    }
}

// getrear function retrieves the last value of the deque.
void getrear()
{
    if ((f == -1) && (r == -1))
    {
        printf("\nDeque is empty.");
    }
    else
    {
        printf("\nRear Element of DeQueue is : %d", deque[r]);
    }
}

// delete_front() function deletes the element from the front
void delete_front()
{
    if ((f == -1) && (r == -1))
    {
        printf("\nDeque is empty.");
    }
    else if (f == r)
    {
        printf("\nThe deleted element is %d", deque[f]);
        f = -1;
        r = -1;
    }
    else if (f == (size - 1))
    {
        printf("\nThe deleted element is %d", deque[f]);
        f = 0;
    }
    else
    {
        printf("\nThe deleted element is %d", deque[f]);
        f = f + 1;
    }
}

// delete_rear() function deletes the element from the rear
void delete_rear()
{
    if ((f == -1) && (r == -1))
    {
        printf("\nDeque is empty.");
    }
    else if (f == r)
    {
        printf("\nThe deleted element is %d", deque[r]);
        f = -1;
        r = -1;
    }
    else if (r == 0)
    {
        printf("\nThe deleted element is %d", deque[r]);
        r = size - 1;
    }
    else
    {
        printf("\nThe deleted element is %d", deque[r]);
        r = r - 1;
    }
}