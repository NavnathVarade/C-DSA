/*There are lists where new elements are always appended at the end of the list. The list can
be implemented as a circular list with the external pointer pointing to the last element of the
list. Implement singly linked circular list of integers with append and display operations. The
operation append(L, n), appends to the end of the list, n integers either accepted from user or
randomly generated.*/

/*We are not using HEAD pointer in circular linked list as next(address) part of last
node indicates begining of linked list. Here last will initially point to first node ,as
new nodes added last moves and will point to the current last node.*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *last = NULL, *newnode, *temp;

void createList()
{
	int n, i;
	printf("Input the number of nodes: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		newnode = (struct node *)malloc(sizeof(struct node)); // Create a new node
		printf("Input data for node %d: ", i + 1);
		scanf("%d", &newnode->data);
		newnode->next = NULL;

		if (last == NULL) // List is empty as last points to the first node
		{
			last = temp = newnode; // Last points to the first node
			last->next = newnode;  // Last holds the address of the first (new) node
		}
		else
		{
			newnode->next = last->next;
			last->next = newnode;
			last = newnode;
		}
	}
}

void displayList()
{
	if (last == NULL)
	{
		printf("The list is empty");
	}
	temp = last->next;
	do
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	} while (temp != last->next);
}

void append()
{
	int data, n, i;
	printf("\nEnter the number of nodes to be appended: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("\nEnter the number to be appended: ");
		scanf("%d", &newnode->data);

		if (last == NULL)
		{
			last = newnode;
			last->next = newnode;
		}
		else
		{
			newnode->next = last->next;
			last->next = newnode;
			last = newnode;
		}
	}
	printf("Updated list:\n");
	displayList();
}

int main()
{
	int choice;

	do
	{
		printf("\n******* OPERATIONS ON SINGLY CIRCULAR LINKED LIST *******\n");
		printf("1: Create a Singly Circular Linked List\n");
		printf("2: Display a Singly Circular Linked List\n");
		printf("3: Append an Element in Singly Circular Linked List\n");
		printf("4: Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			createList();
			break;
		case 2:
			printf("\nData entered in the list:\n");
			displayList();
			break;
		case 3:
			append();
			break;
		case 4:
			exit(0);
		default:
			printf("Invalid Choice\n");
		}
	} while (choice != 4);

	return 0;
}
