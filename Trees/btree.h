#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lchild, *rchild;
};

struct node *createnode(struct node *newnode, int data)
{
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->lchild = newnode->rchild = NULL;
    return newnode;
}

void insert(struct node **root, int data)
{
    struct node *newnode;
    newnode = createnode(newnode, data);
    if (*root == NULL)
        *root = newnode;
    else
    {
        struct node *temp = *root;
        while (1)
        {
            if (data < temp->data)
            {
                if (temp->lchild == NULL)
                {
                    temp->lchild = newnode;
                    break;
                }
                temp = temp->lchild;
            }
            else
            {
                if (temp->rchild == NULL)
                {
                    temp->rchild = newnode;
                    break;
                }
                temp = temp->rchild;
            }
        }
    }
}

void createbst(struct node **root)
{
    int n, i;
    int data;
    printf("\nEnter the how many nodes : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the Data for Node : ");
        scanf("%d", &data);
        insert(root, data);
    }
}

void display(struct node *temp)
{
    if (temp)
    {
        printf("%d\t", temp->data);
        display(temp->lchild);
        display(temp->rchild);
    }
}

void search(struct node *temp, int data)
{
    if (temp)
    {
        if (temp->data == data)
        {
            printf("\nData Found");
            return;
        }
        search(temp->lchild, data);
        search(temp->rchild, data);
    }
}