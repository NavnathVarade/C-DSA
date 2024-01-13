/*Program to Insert a node at Beginning,End and At given Postion*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *temp, *newnode;

// Function prototypes
void createList();
void displayList();
void insertAtFront();
void insertAtEnd();
void insertAtPosition();

int main() {
    int choice;

    printf("Linked List: Create, display, and perform insertions\n");
    createList();
    printf("\nData entered in the list:\n");
    displayList();

    do {
        printf("\n********** Insertion on Singly Linked List **********\n");
        printf("1. Insert at the Beginning\n");
        printf("2. Insert at the End\n");
        printf("3. Insert at a Specific Position\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertAtFront();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                insertAtPosition();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}


void createList()
{
	int n, i;
	printf("\nInput the number of nodes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("\nInput data for node %d: ",i+1);
		scanf("%d", &newnode->data);
		newnode->next = NULL; 
		if(head==NULL)
		{
			head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
	}
}

void displayList()
{
	int cnt=0;
	temp=head;
	while(temp!= NULL)
	{
		printf(" %d \t", temp->data);
		temp=temp->next;
		cnt++;
	}        
	printf("\n Number of nodes are : %d\n",cnt);
} 

void insertAtFront()
{
	int data;
	struct node* newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter number to be inserted : ");
	scanf("%d", &newnode->data);
	newnode->next = NULL;
	if(head==NULL)
		head=newnode;
	else
	{
		newnode->next = head; //pointer from new node to previous first node
		head = newnode; // head will point to new node
	}
	printf("Updated list is : \n");
	displayList();
}

void insertAtEnd()
{
	int data;
	struct node *newnode, *last;
	newnode =(struct node*) malloc(sizeof(struct node));
	printf("\nEnter number to be inserted : ");
	scanf("%d", &newnode->data);
	newnode->next = NULL;
	if(head==NULL)
		head=last=newnode;
	temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	} //to traverse linked list upto last node,temp will point to previous last node
	temp->next = newnode; //link from previous last node to new node*/
	printf("Updated list is : \n");
	displayList();
}

void insertAtPosition()
{
	struct node *newnode;
	int pos, data, i = 1;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter position and data :");
	scanf("%d %d", &pos, &newnode->data);
	// Change Links
	newnode->next= NULL;
	temp = head;
	if(pos==1)
	{
		newnode->next=head;
		head=newnode;
	}
	while (i < pos - 1)
	{
		temp = temp->next;
		i++;
	}
	newnode->next = temp->next;
	temp->next = newnode;
	printf("Updated list is : \n");
	displayList();
}

