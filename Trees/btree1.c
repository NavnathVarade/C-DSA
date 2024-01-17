/*
Implement a Binary search tree (BST) library (btree.h) with operations – create, search,
insert, inorder, preorder and postorder. Write a menu driven program that performs the 
above operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include "btree1.h"

int main()
{
    struct node *root = NULL, *temp;
    int n, i, ch, data, val;

    do
    {
        printf("\n-----MENU-----\n");
        printf("1. Create BST.\n");
        printf("2. Insert a Node in BST.\n");
        printf("3. Search a Node from BST.\n");
        printf("4. Display BST.\n");
        printf("5. Inorder Traversal.\n");
        printf("6. Preorder Traversal.\n");
        printf("7. Postorder Traversal.\n");
        printf("8. Exit.\n\n");
        printf("Enter Your Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter how many nodes you want : \n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("Enter node values for %dth node : ", i + 1);
                scanf("%d", &val);
                root = create(root, val);
            }
            break;

        case 2:
            printf("\nEnter data to be inserted in BST : ");
            scanf("%d", &data);
            root = insert(root, data);
            break;

        case 3:
            printf("\nEnter node to be searched : ");
            scanf("%d", &data);
            temp = search(root, data);
            if (temp == NULL)
                printf("\n%d is Not Found in BST.", data);
            else
                printf("\n%d is Found in BST.", data);
            break;

        case 4:
            display(root);
            break;

        case 5:
            inorder(root);
            break;

        case 6:
            preorder(root);
            break;

        case 7:
            postorder(root);
            break;
        case 8:
            exit(0);
            break;

        default:
            printf("\nInvalid Choice.");
        }

    } while (ch != 8);

    return 0;
}