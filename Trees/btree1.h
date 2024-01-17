#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lchild, *rchild;
};

struct node *create(struct node *root, int data)
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = data;
        root->lchild = root->rchild = NULL;
        return root;
    }
    else if (data < root->data)
    {
        root->lchild = create(root->lchild, data);
    }
    else if (data > root->data)
    {
        root->rchild = create(root->rchild, data);
    }
    return root;
}

struct node *insert(struct node *root, int key)
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = key;
        root->lchild = root->rchild = NULL;
        return root;
    }
    else if (key < root->data)
    {
        root->lchild = insert(root->lchild, key);
    }
    else if (key > root->data)
    {
        root->rchild = insert(root->rchild, key);
    }

    return root;
}

struct node *search(struct node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == data)
    {
        return root;
    }
    else if (data < root->data)
    {
        return (search(root->lchild, data));
    }
    else if (data > root->data)
    {
        return (search(root->rchild, data));
    }
};

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->data);
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
