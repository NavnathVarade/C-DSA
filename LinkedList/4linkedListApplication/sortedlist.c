/*
Write a program that sorts the elements of linked list using any of sorting technique.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head, *tail = NULL, *newnode, *temp;

// Function to create a singly linked list
void createList()
{
	int n, i;
	printf("\nInput the number of nodes : ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("\nInput data for node %d: ", i + 1);
		scanf("%d", &newnode->data);
		newnode->next = NULL;

		if (head == NULL)
		{
			head = temp = newnode;
		}
		else
		{
			temp->next = newnode;
			temp = newnode;
		}
	}
}

// Function to sort a singly linked list using bubble sort
void sortList()
{
	struct node *current = head, *ptr = NULL;
	int temp;

	if (head == NULL)
	{
		return;
	}
	else
	{
		while (current != NULL)
		{
			ptr = current->next;
			while (ptr != NULL)
			{
				if (current->data > ptr->data)
				{
					// Swap data if the current node's data is greater than the next node's data
					temp = current->data;
					current->data = ptr->data;
					ptr->data = temp;
				}
				ptr = ptr->next;
			}
			current = current->next;
		}
	}
}

// Function to display a singly linked list
void displayList()
{
	temp = head;
	if (head == NULL)
	{
		printf("List is empty \n");
		return;
	}
	while (temp != NULL)
	{
		printf(" %d \t", temp->data);
		temp = temp->next;
	}
}

void main()
{
	int n;
	printf("\nLinked List : To create and display Singly Linked List :");
	createList();
	printf("\nOriginal Linked List is : \n");
	displayList();
	sortList();
	printf("\nSorted Linked List is : \n");
	displayList();
}
