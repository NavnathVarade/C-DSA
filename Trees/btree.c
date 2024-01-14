/*
Implement a Binary search tree (BST) library (btree.h) with operations – create, search,
insert. Write a menu driven program that performs the above operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

int main()
{
    struct node *root = NULL;
    int ch;
    do
    {
        printf("\n-----MENU-----\n");
        printf("\n1. Create BST.");
        printf("\n2. Insert a Node in BST.");
        printf("\n3. Search a Node from BST.");
        printf("\n4. Display BST.");
        printf("\n5. Exit.");
        printf("\nEnter Your Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            createbst(&root);
            break;
        case 2:
        {
            int data;
            printf("\nEnter data to be inserted in BST : ");
            scanf("%d", &data);
            insert(&root, data);
        }
        break;
        case 3:
        {
            int node;
            printf("\nEnter node to be searched : ");
            scanf("%d", &node);
            search(root, node);
        }
        break;
        case 4:
            display(root);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nInvalid Choice.");
        }
    } while (ch != 5);
    return 0;
}