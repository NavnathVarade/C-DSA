#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;                        
	struct node *next;
	struct node *prev;
};

struct node *head = NULL, *newnode, *temp;

void createList()
{
	int n, i;
	printf("\nInput the number of nodes : ");
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("\nInput data for node %d: ", i + 1);
		scanf("%d", &newnode->data);
		newnode->next = NULL; 
		newnode->prev = NULL;

		if(head == NULL)
		{
			head = temp = newnode;
		}
		else
		{
			temp->next = newnode;
			newnode->prev = temp;
			temp = newnode;
			temp->next = NULL;
		}
	}
}

void displayList()
{
	int cnt = 0;
	temp = head;

	while(temp != NULL)
	{
		printf(" %d \t", temp->data);       // prints the data of the current node
		temp = temp->next;                    // advances the position of the current node
		cnt++;
	}        

	printf("\n Number of nodes are : %d\n", cnt);
} 

void reverse()
{
	struct node *prevnode, *currentnode, *nextnode;
	prevnode = NULL;
	currentnode = nextnode = head;

	while(nextnode != NULL)
	{
		nextnode = nextnode->next;
		currentnode->next = prevnode;
		currentnode->prev = nextnode; // adjusting prev pointer as well for doubly linked list
		prevnode = currentnode;
		currentnode = nextnode;
	}

	head = prevnode;
	printf("\nReverse Linked List is : ");
	displayList();
}
