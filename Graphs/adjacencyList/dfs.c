/*
Write a C program that accepts the vertices and edges of a graph and store it as an adjacency list. Implement function to 
traverse the graph using Depth First Search (DFS) traversal.
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct node 
{
	int vertex;
	struct node *next;
}*v[10];

int visited[MAX];

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

void DFS(int start)
{
	struct node *temp;
	printf("%d\t",start);
	temp=v[start];
	visited[start]=1;
	while(temp!=NULL)
	{
		start=temp->vertex;
		if(!visited[start])
		DFS(start);
		temp=temp->next;
	}
}

void main()
{
	int m[10][10],n,i,start;
	printf("\nEnter Number of Vertices : ");
	scanf("%d",&n);
	create(m,n);
	createlist(m,n);
	display(n);
	for(i=0;i<n;i++)
		visited[i]=0;
	printf("\nEnter the Starting Vertex : ");
	scanf("%d",&start);
	printf("\nDFS Traversal is : \n");
	DFS(start);
}