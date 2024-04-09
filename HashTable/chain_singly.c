/*
Implement hash table using singly linked lists. Write a menu driven program to perform operations on the hash table (insert,
search, delete, display). Select appropriate hashing function. In case of collision, use separate chaining.
*/

#include <stdio.h>
#include <stdlib.h>
#include "chain_singly.h"

int main()
{
	int key, i, n, choice;

	do
	{
		printf("\n--------MENU--------");
		printf("\n1.Create Hash Table");
		printf("\n2.Insert");
		printf("\n3.Search data");
		printf("\n4.Delete by data");
		printf("\n5.Display all elements");
		printf("\n6.Exit");

		printf("\nEnter your choice : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\nEnter no. of elements : ");
			scanf("%d", &n);

			for (i = 0; i < n; i++)
			{
				printf("\nEnter the data : ");
				scanf("%d", &key);
				insert(key);
			}
			break;

		case 2:
			printf("\nEnter no. of elements to insert : ");
			scanf("%d", &n);

			for (i = 0; i < n; i++)
			{
				printf("\nEnter the data : ");
				scanf("%d", &key);
				insert(key);
			}
			break;

		case 3:
			printf("\nEnter the data to search : ");
			scanf("%d", &key);

			if (search(key))
				printf("%d is found in hash table\n", key);
			else
				printf("%d not found in hash table\n", key);

			break;

		case 4:
			printf("\nEnter the data to Delete : ");
			scanf("%d", &key);

			if (delete_by_data(key))
			{
				printf("%d is deleted\n", key);
				printf("\nUpdated Hash Table : ");
				display();
			}
			else
				printf("%d not found in hash table\n", key);

			break;

		case 5:
			printf("\nDisplaying all elements : ");
			display();
			break;

		case 6:
			exit(0);

		default:
			printf("\nWrong input!");
		}
	} while (choice != 6);

	return 0;
}
