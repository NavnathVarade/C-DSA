/*
Write a menu driven program to implement hash table using array (insert, search, delete, display). Use any of the above-
mentioned hash functions. In case of collision apply quadratic probing.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct table
{
    int data;
    int status; // status is used to indicate if data is present at the location
} HT[SIZE];

int division_Hashing(int key)
{
    if (key > 0)
        return key % SIZE;
    else
        return -key % SIZE;
}

int quadratic_probing(int hash)
{
    int i, new_hash;
    for (i = 0; i < SIZE; i++)
    {
        new_hash = (hash + i * i) % SIZE;
        if (HT[new_hash].status == 0)
            return new_hash;
        else
            printf("Collision occurred at index %d\n", new_hash);
    }
    printf("Hash table is full. Unable to insert.\n");
    return -1;
}

int insert(int key)
{
    int hash = division_Hashing(key);
    if (HT[hash].status == 0)
    {
        HT[hash].data = key;
        HT[hash].status = 1;
        return hash;
    }
    else
    {
        int new_hash = quadratic_probing(hash);
        if (new_hash != -1)
        {
            HT[new_hash].data = key;
            HT[new_hash].status = 1;
            return new_hash;
        }
    }
    return -1;
}

void display()
{
    printf("\nIndex\tData\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t", i);
        if (HT[i].status == 1)
            printf("%d\n", HT[i].data);
        else
            printf("-\n");
    }
}

int search(int target)
{
    int hash = division_Hashing(target);
    if (HT[hash].data == target)
        return hash;
    else
    {
        for (int i = hash + 1; i % SIZE != hash; i = (i + 1) % SIZE)
        {
            if (HT[i].status == 1 && HT[i].data == target)
                return i;
        }
    }
    return -1;
}

void delete (int target)
{
    int hash = division_Hashing(target);
    if (HT[hash].data == target)
    {
        HT[hash].status = 0;
        printf("%d deleted from Hash Table\n", target);
    }
    else
    {
        for (int i = hash + 1; i % SIZE != hash; i = (i + 1) % SIZE)
        {
            if (HT[i].status == 1 && HT[i].data == target)
            {
                HT[i].status = 0;
                printf("%d deleted from Hash Table\n", target);
                return;
            }
        }
        printf("%d not found in Hash Table\n", target);
    }
}

int main()
{
    int choice, data, target, pos;
    do
    {
        printf("\n-----MENU-----");
        printf("\n1.Insert\n2.Search data\n3.Delete data\n4.Display\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the number of elements: ");
            int n;
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("Enter the data: ");
                scanf("%d", &data);
                int hash = insert(data);
                if (hash != -1)
                    printf("Hashed at index %d\n", hash);
            }
            break;
        case 2:
            printf("\nEnter the element to be searched: ");
            scanf("%d", &target);
            pos = search(target);
            if (pos == -1)
                printf("%d not found in hash table\n", target);
            else
                printf("%d hashed at index %d\n", target, pos);
            break;
        case 3:
            printf("\nEnter the data to delete: ");
            scanf("%d", &target);
            delete (target);
            printf("Updated hash table: ");
            display();
            break;
        case 4:
            printf("\nDisplaying elements of hash table:\n");
            display();
            break;
        case 5:
            break;
        default:
            printf("\nInvalid input!\n");
        }
    } while (choice != 5);
    return 0;
}

