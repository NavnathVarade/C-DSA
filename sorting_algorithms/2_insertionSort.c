#include <stdio.h>

void insertionSort(int arr[], int n);

int main() {
    int arr[20], i, n;

    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nArray Elements Before Sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    insertionSort(arr, n);

    printf("\nArray Elements After Sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    return 0;
}

void insertionSort(int arr[], int n) {
    int j, k, key;
    for (j = 1; j < n; j++) {
        key = arr[j];
        k = j - 1;
        while (k >= 0 && arr[k] > key) {
            arr[k + 1] = arr[k];
            arr[k] = key;
            k = k - 1;
        }
    }
}
