#include <stdio.h>

// Function prototypes
void merge(int a[], int low, int mid, int high);
void mergeSort(int a[], int low, int high);

int main() {
    int a[20], i, n;

    printf("\nEnter the value of n: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nArray Elements Before Sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    mergeSort(a, 0, n - 1);

    printf("\nArray Elements After Sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    return 0;
}

void merge(int a[], int low, int mid, int high) {
    int i, j, k, b[20];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    if (i > mid) {
        while (j <= high) {
            b[k] = a[j];
            j++;
            k++;
        }
    } else {
        while (i <= mid) {
            b[k] = a[i];
            i++;
            k++;
        }
    }

    for (k = low; k <= high; k++) {
        a[k] = b[k];
    }
}

void mergeSort(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
