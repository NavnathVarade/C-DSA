/*
Write a program to sort n randomly generated elements using Heapsort method.
*/

#include <stdio.h>

void heapify(int a[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && a[left] > a[largest])
		largest = left;
	if (right < n && a[right] > a[largest])
		largest = right;
	if (largest != i)
	{
		// swap a[i] with a[largest]
		int temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		heapify(a, n, largest);
	}
}

/*Function to implement the heap sort*/
void heapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--)
	{
		/* Move current root element to end*/
		// swap a[0] with a[i]
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapify(a, i, 0);
	}
}

void printArr(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d", arr[i]);
		printf(" ");
	}
}

int main()
{
	int arr[10], i, n;
	printf("\nEnter no of elements :");
	scanf("%d", &n);
	printf("\nEnter the nos : ");
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("Before sorting array elements are - \n");
	printArr(arr, n);
	heapSort(arr, n);
	printf("\nAfter sorting array elements are - \n");
	printArr(arr, n);
	return 0;
}
