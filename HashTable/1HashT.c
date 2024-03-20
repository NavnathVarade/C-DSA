/*
Write a program to implement various types of hash functions which are used to place the data in a hash table
a. Division Method
b. Mid Square Method
c. Digit Folding Method
Accept n values from the user and display appropriate message in case of collision for each of the above functions.
*/

#include <stdio.h>
#include <string.h>
#define SIZE 10

struct table
{
    int data;
    int status; // status is used to see if data is presented at the location or not
} HT[SIZE];     // if status = 1 data is present if 0 data is not present

int division(int key)
{
    int hash;

    hash = key % 10;

    if (hash < 0) // if value of hash is negative converting it into positive
        hash = hash * -1;

    if (HT[hash].status == 0) // if status is 0 it means location is empty and we
    {                         // we can store data at that location
        HT[hash].data = key;
        HT[hash].status = 1;
        return hash;
    }

    else
        return -1;
}

int midSquare(int key)
{
    int square, mid, hash;
    char str[10];

    square = key * key;

    sprintf(str, "%d", square);

    mid = (strlen(str) - 1) / 2;
    hash = str[mid] - '0';

    if (HT[hash].status == 0)
    {
        HT[hash].data = key;
        HT[hash].status = 1;
        return hash;
    }

    else
        return -1;
}

int digitFolding(int key)
{
    int sum, hash, num;

    if (key < 0) // if value of hash is negative converting it into positive
        key = key * -1;

    num = key;
    sum = 0;

    while (num > 0)
    {
        sum = sum + (num % 10);
        num = num / 10;
    }
    hash = sum;

    if (HT[hash].status == 0)
    {
        HT[hash].data = key;
        HT[hash].status = 1;
        return hash;
    }

    else
        return -1;
}

void display()
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        // if(HT[i].status == 1) //we only print if status is 1 as it indicates data is present
        printf("%d ", HT[i].data);
    }
}

int main()
{
    int n, i, data, choice, hash;

    for (i = 0; i < SIZE; i++)
    {
        HT[i].data = -1;
    }

    printf("\n----MENU----\n");
    printf("\n1.Division Method");
    printf("\n2.Mid Square Method");
    printf("\n3.Digit Folding Method");

    printf("\nEnter your hash function : ");
    scanf("%d", &choice);

    printf("\nEnter the number of elements : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter the data : ");
        scanf("%d", &data);

        switch (choice)
        {
        case 1:
            hash = division(data);

            if (hash == -1)
                printf("Collision detected, value skipped..\n");

            else
                printf("Hashed at index %d\n", hash);
            break;

        case 2:
            hash = midSquare(data);

            if (hash == -1)
                printf("Collision detected, value skipped..\n");

            else
                printf("Hashed at index %d\n", hash);
            break;

        case 3:
            hash = digitFolding(data);

            if (hash == -1)
                printf("Collision detected, value skipped..\n");

            else
                printf("Hashed at index %d\n", hash);
            break;
        }
    }

    printf("\nDisplaying elements of Hash Table : ");
    display();

    return 0;
}