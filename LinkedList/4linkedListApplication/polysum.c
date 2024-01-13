/*
Write a program that adds two single variablepolynomials. Each polynomial should be
represented as a list with linked list implementation.
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int coef, exp;
	struct node *next;
};

struct node *newnode = NULL, *last = NULL, *head1 = NULL, *head2 = NULL, *head3 = NULL;

// Function to create a polynomial linked list
struct node *createpolynomial(struct node *head)
{
	int i, n, c;
	struct node *temp = head;

	printf("\nEnter the Highest Exponent for the Polynomial : ");
	scanf("%d", &n);

	for (i = n; i >= 0; i--)
	{
		printf("\nEnter the coefficient for the term with exponent %d : ", i);
		scanf("%d", &c);

		if (c == 0)
			continue;

		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->next = NULL;
		newnode->coef = c;
		newnode->exp = i;

		if (head == NULL)
			head = last = newnode;
		else
		{
			last->next = newnode;
			last = newnode;
		}
	}

	return head;
}

// Function to display a polynomial linked list
void display(struct node *head)
{
	struct node *temp = head;
	while (temp != NULL)
	{
		printf("(%dx^%d)+", temp->coef, temp->exp);
		temp = temp->next;
	}
}

// Function to add two polynomial linked lists
struct node *addpolynomial(struct node *head1, struct node *head2)
{
	struct node *p1 = head1, *p2 = head2, *newnode = NULL, *head3 = NULL, *last = NULL;

	// Check if either of the polynomials is empty
	if (head1 == NULL || head2 == NULL)
	{
		if (head1 == NULL)
			head3 = head2;
		else
			head3 = head1;
	}
	else
	{
		// Traverse both polynomials until one of them reaches the end
		while (p1 != NULL && p2 != NULL)
		{
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->next = NULL;

			if (p1->exp == p2->exp)
			{
				newnode->exp = p1->exp;
				newnode->coef = p1->coef + p2->coef;
				p1 = p1->next;
				p2 = p2->next;
			}
			else
			{
				if (p1->exp > p2->exp)
				{
					newnode->exp = p1->exp;
					newnode->coef = p1->coef;
					p1 = p1->next;
				}
				else
				{
					newnode->exp = p2->exp;
					newnode->coef = p2->coef;
					p2 = p2->next;
				}
			}

			if (head3 == NULL)
				head3 = last = newnode;
			else
			{
				last->next = newnode;
				last = newnode;
			}
		}

		// Add remaining terms of the first polynomial
		while (p1 != NULL)
		{
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->next = NULL;
			newnode->exp = p1->exp;
			newnode->coef = p1->coef;
			p1 = p1->next;
			last->next = newnode;
			last = newnode;
		}

		// Add remaining terms of the second polynomial
		while (p2 != NULL)
		{
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->next = NULL;
			newnode->exp = p2->exp;
			newnode->coef = p2->coef;
			p2 = p2->next;
			last->next = newnode;
			last = newnode;
		}
	}

	return head3;
}

int main()
{
	printf("\nCreate First Polynomial : \n");
	head1 = createpolynomial(head1);
	printf("\n First Polynomial is : \n");
	display(head1);

	printf("\nCreate Second Polynomial : \n");
	head2 = createpolynomial(head2);
	printf("\n Second Polynomial is : \n");
	display(head2);

	head3 = addpolynomial(head1, head2);
	printf("\n Addition of Two Polynomials is : \n");
	display(head3);

	return 0;
}
