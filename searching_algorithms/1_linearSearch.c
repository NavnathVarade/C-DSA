/*Create a random array of n integers. Accept a value x from user and use linear search
algorithm to check whether the number is present in the array or not and output the position if
the number is present.*/

#include <stdio.h>
int linearSearch(int arr[10], int n, int num);
void accept(int arr[10], int n);
void display(int arr[10], int n);

int main()
{
    int arr[10], i, n, num;
    printf("How value of n: ");
    scanf("%d", &n);
    printf("\nEnter the number of array : ");

    accept(arr, n);
    display(arr, n);

    printf("\nEnter the number to be searched : ");
    scanf("%d", &num);
    i = linearSearch(arr, n, num);

    if (i == -1)
        printf("\n%d is not found in the array.\n", num);
    else
        printf("\n%d is found at location %d in the array\n", num, i + 1);
    return 0;
}

void accept(int arr[10], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\nElement %d : ",i+1);
        scanf("%d", &arr[i]);
    }
}

void display(int num[10], int n)
{
    int i;
    printf("\nThe entered array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", num[i]);
    }
}

int linearSearch(int arr[10], int n, int num)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == num)
            return i;
    }
    return -1;
}