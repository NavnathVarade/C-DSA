#include <stdio.h>
#include <stdlib.h>
#define NEWNODE (struct node *)malloc(sizeof(struct node))
#define SIZE 10

struct node
{
	int data;
	int status;		   //	status tells us whether data is present
	struct node *next; //	or not in that node. If data is present
} HT[SIZE];			   //  status = 1 else status = 0

int hash(int key)
{
	return key < 0 ? -key % SIZE : key % SIZE; // if key is negative we make it positive
} // by using '-key' its a simple hash function key%SIZE

void insert(int key)
{
	int hash_value;
	struct node *link = NULL, *t = NULL;

	hash_value = hash(key);

	if (HT[hash_value].status == 0)
	{
		HT[hash_value].data = key;
		HT[hash_value].status = 1; // as data is accupied in this node
	}							   // we assign status = 1

	else // this else will run only in case of collision
	{
		link = NEWNODE;
		link->data = key;
		link->status = 1;
		link->next = NULL;

		t = &HT[hash_value];

		while (t->next) // traversing till the end of list
			t = t->next;

		t->next = link;
	}
}

int delete_by_data(int key)
{
	int index;
	struct node *f, *t;

	index = hash(key);

	if (HT[index].status == 1 || HT[index].next != NULL)
	{
		if (HT[index].data == key)
		{
			HT[index].data = HT[index].status = 0;
			return 1;
		}
		else // this else will only run if data is in linked list associated with HT[index]
		{
			f = &HT[index];

			while (f->next != NULL) // logic similar to linear search
			{
				if (f->next->data == key)
				{
					t = f->next;
					f->next = t->next;
					free(t);
					return 1;
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
	int index = hash(target);
	struct node *t;

	if (HT[index].status)
	{
		if (HT[index].data == target)
			return 1;

		else // this else will only run to check
		{	 // if data is in linked list
			t = &HT[index];
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
		if (HT[i].status)
		{
			printf("\n  %d\t%d", i, HT[i].data);

			if (HT[i].next != NULL)
			{
				t = &HT[i];
				t = t->next;

				while (t)
				{
					printf("->%d", t->data);
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
					printf("->%d", t->data);
					t = t->next;
				}
			}
		}
	}
}
