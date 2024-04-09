#include <stdio.h>
#include <stdlib.h>
#define NEWNODE (struct node *)malloc(sizeof(struct node))
#define SIZE 10

struct node
{
	int data;
	int status;		   // status tells us whether data is present
	struct node *next; // or not in that node. If data is present
	struct node *prev; // status = 1 else status = 0
} HT[SIZE];

int division_hashing(int key)
{
	if (key < 0)
		return -key % SIZE;
	else
		return key % SIZE;
}

void insert(int key)
{
	int hash;
	struct node *link = NULL, *t = NULL;

	hash = division_hashing(key);

	if (HT[hash].status == 0)
	{
		HT[hash].data = key;
		HT[hash].status = 1; // as data is accupied in this node
	}						 // we assign status = 1

	else // this else will run only in case of collision
	{
		link = NEWNODE;
		link->data = key;
		link->status = 1;
		link->next = link->prev = NULL;

		t = &HT[hash];

		while (t->next) // traversing till the end of list
			t = t->next;

		t->next = link;
		link->prev = t;
	}
}

int delete_by_data(int key)
{
	int hash;
	struct node *f, *t, *s;

	hash = division_hashing(key);

	if (HT[hash].status == 1 || HT[hash].next != NULL)
	{
		if (HT[hash].data == key)
		{
			HT[hash].data = HT[hash].status = 0;
			return 1;
		}
		else // this else will only run if data is in linked list associated with HT[hash]
		{
			f = &HT[hash];

			while (f->next != NULL) // logic similar to linear search
			{
				if (f->next->data == key)
				{
					t = f->next;
					s = t->next;

					if (s == NULL)
					{
						f->next = NULL;
						free(t);
						return 1;
					}

					else
					{
						f->next = s;
						s->prev = f;
						free(t);
						return 1;
					}
				}

				f = f->next;
			}
			return 0;
		}
	}
	else
		return 0;
}

int search(int target)
{
	int hash = division_hashing(target);
	struct node *t;

	if (HT[hash].status)
	{
		if (HT[hash].data == target)
			return 1;

		else // this else will only run to check if data
		{	 // is in linked list
			t = &HT[hash];
			t = t->next;

			while (t) // linear search
			{
				if (t->data == target)
					return 1;

				t = t->next;
			}
			return 0;
		}
	}
	else
		return 0;
}

void display()
{
	int i;
	struct node *t;

	printf("\nIndex  Data");

	for (i = 0; i < SIZE; i++)
	{
		if (HT[i].status == 1)
		{
			printf("\n  %d\t%d", i, HT[i].data);

			if (HT[i].next != NULL)
			{
				t = &HT[i];
				t = t->next;

				while (t)
				{
					printf(" <-> %d", t->data);
					t = t->next;
				}
			}
		}
		else
		{
			printf("\n  %d\t-", i);

			if (HT[i].next != NULL)
			{
				t = &HT[i];
				t = t->next;

				while (t)
				{
					printf(" <-> %d", t->data);
					t = t->next;
				}
			}
		}
	}
}
