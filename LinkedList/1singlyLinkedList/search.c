/*Program to Search an element in a Linked List*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *newnode, *temp;

// Function prototypes
void createList();
void displayList();
void search();

int main() {
    printf("Linked List: Search an element in a singly linked list\n");
    createList();
    printf("\nData entered in the list:\n");
    displayList();
    search();

    return 0;
}

void search() {
    struct node *ptr;
    int element, i = 0, flag = 0;

    if (head == NULL) {
        printf("\nLinked List is empty.\n");
    } else {
        printf("\nEnter the element to be searched: ");
        scanf("%d", &element);

        ptr = head;
        while (ptr != NULL) {
            if (ptr->data == element) {
                printf("\nElement %d is found at location %d.\n", element, i + 1);
                flag = 1;
                break; // Once found, no need to continue searching
            }
            i++;
            ptr = ptr->next;
        }

        if (flag == 0) {
            printf("\nElement %d not found in the Linked List.\n", element);
        }
    }
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

void displayList() {
	int cnt=0;
	temp=head;
	while(temp!= NULL)
	{
		printf(" %d \t", temp->data);       // prints the data of current node
		temp=temp->next;                    // advances the position of current node
		cnt++;
	}        
	printf("\n Number of nodes are : %d\n",cnt);
} 