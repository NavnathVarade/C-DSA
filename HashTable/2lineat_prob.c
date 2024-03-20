/*
Write a menu driven program to implement hash table using array (insert, search, delete, display). Use any of the above-
mentioned hash functions. In case of collision apply linear probing)
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct table
{
    int data;
    int status;
} HT[SIZE];

int division_Hashing(int key)
{
    if (key > 0)
        return key % SIZE;
    else
        return -key % SIZE;
}

int linear_probing(int index)
{
    int i;

    i = index;

    while (1)
    {
        i = (i + 1) % SIZE; // similar to traversing circular queue

        if (i == index)
            return -1;

        if (HT[i].status == 0)
            return i;
    }
}

void insert(int key)
{
    int i, hash, new_hash;

    hash = division_Hashing(key);

    if (HT[hash].status == 0)
    {
        HT[hash].data = key;
        HT[hash].status = 1;

        printf("Hashed at index %d\n", hash);
    }

    else
    {
        printf("\nCollison Detected, Applying Linear Probing .\n");
        new_hash = linear_probing(hash);

        if (new_hash == -1)
            printf("\nHash Table is full!");

        else
        {
            HT[new_hash].data = key;
            HT[new_hash].status = 1;

            printf("Hashed at index %d\n", new_hash);
        }
    }
}

void display()
{
    int i;

    printf("\nindex  data");

    for (i = 0; i < SIZE; i++)
    {
        if (HT[i].status == 1)
            printf("\n  %d  :  %d", i, HT[i].data);
    }
}

int search(int target)
{
    int hash, i;

    hash = division_Hashing(target);

    if (HT[hash].data == target)
        return hash;

    else
    {
        i = hash + 1;

        while (i != hash)
        {
            if (HT[i].status == 1 && HT[i].data == target)
                return i;

            i = (i + 1) % SIZE;
        }
        return -1;
    }
}

void delete(int target)
{
    int hash, i, flag = 1;

    hash = division_Hashing(target);

    if (HT[hash].data == target)
    {
        HT[hash].status = 0;
        printf("\n%d deleted from Hash Table", target);
    }

    else
    {
        i = hash + 1;

        while (i != hash)
        {
            if (HT[i].status == 1 && HT[i].data == target)
            {
                HT[i].status = 0;
                flag = 0;
                printf("\n%d deleted from Hash Table", target);
            }

            i = (i + 1) % SIZE;
        }

        if (flag == 1)
            printf("\n%d not found in Hash Table", target);
    }
}

int main()
{
    int n, choice, i, data, target, pos;

    do
    {
        printf("\n-----MENU-----");
        printf("\n1.Insert\n2.Search data\n3.Delete data\n4.Display\n5.Exit");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the number of elements : ");
            scanf("%d", &n);

            for (i = 0; i < n; i++)
            {
                printf("\nEnter the data : ");
                scanf("%d", &data);
                insert(data);
            }
            break;

        case 2:
            printf("\nEnter the element to be searched : ");
            scanf("%d", &target);

            pos = search(target);

            if (pos == -1)
                printf("\n%d not found in hash table", target);

            else
                printf("\n%d hashed at index %d", target, pos);
            break;

        case 3:
            printf("\nEnter the data to delete : ");
            scanf("%d", &target);
            delete (target);

            printf("\nUpdated hash table : ");
            display();
            break;

        case 4:
            printf("\nDisplaying elements of hash table : ");
            display();
            break;

        case 5:
            break;

        default:
            printf("\nInvalid input!");
        }
    } while (choice != 5);

    return 0;
}