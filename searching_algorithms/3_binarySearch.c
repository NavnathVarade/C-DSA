/* Accept n sorted values in array from user. Accept a value x from user and use binary
search algorithm to check whether the number is present in sorted array or not and output the
position if the number is present.*/

#include <stdio.h>
void accept(int a[], int n);
void binarysearch(int low, int high, int a[], int key);

int main()
{
    int a[10], i, n, key, high, low = 0, mid;
    printf("how many element you want to store in array : ");
    scanf("%d", &n);

    printf("Enter the element in array:");
    accept(a, n);

    printf("Array elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nEnter number to search:");
    scanf("%d", &key);
    binarysearch(0, n - 1, a, key);
}

void binarysearch(int low, int high, int a[], int key)
{
    int mid;
    if (low > high)
    {
        printf("\n%d is not found in the array.\n", key);
        return;
    }
    mid = (low + high) / 2;
    if (key == a[mid])
    {
        printf("\n%d is found at position %d in the array\n", key, mid + 1);
        return;
    }
    else if (key < a[mid])
    {
        return binarysearch(low, mid - 1, a, key);
    }
    else if (key > a[mid])
    {
        return binarysearch(mid + 1, high, a, key);
    }
}

void accept(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("\nelement %d : ", i + 1);
        scanf("%d", &a[i]);
    }
}
