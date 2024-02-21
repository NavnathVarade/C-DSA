/*
Write a C program that accepts the vertices and edges of a graph. Create adjacency list and display the adjacency list.
*/

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int vertex;
	struct node *next;
}*v[10];

void create(int m[10][10],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			m[i][j]=0;
			if(i!=j)
			{
				printf("\nIs there an edge between %d and %d : ",i+1,j+1);
				scanf("%d",&m[i][j]);
			}
		}
	}
}

void createlist(int m[10][10], int n)
{
	int i,j;
	struct node *temp,*newnode;
	for(i=0;i<n;i++)
	{
		v[i]=NULL;
		for(j=0;j<n;j++)
		{
			if(m[i][j]==1)
			{
				newnode=(struct node *)malloc(sizeof(struct node));
				newnode->next=NULL;
				newnode->vertex=j+1;
				if(v[i]==NULL)
					v[i]=temp=newnode;
				else
				{
					temp->next=newnode;
					temp=newnode;
				}
			}
		}
	}
}

void display(int n)
{
	struct node *temp;
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nv%d | ",i+1);
		temp=v[i];
		while(temp)
		{
			printf("v%d -> ",temp->vertex);
			temp=temp->next;
		}
		printf("NULL");
	}
}

void main()
{
	int m[10][10],n;
	printf("\nEnter Number of Vertices : ");
	scanf("%d",&n);
	create(m,n);
	createlist(m,n);
	display(n);
}