#include <stdio.h>

// Function prototypes
void displayArray(int a[], int n);
void bubbleSort(int a[], int n);

int main() {
    int n, i, a[100];

    printf("Enter the number of array elements: \n");
    scanf("%d", &n);

    printf("Enter array elements: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Before sorting, array elements are: \n");
    displayArray(a, n);

    bubbleSort(a, n);

    printf("\nAfter sorting, array elements are: \n");
    displayArray(a, n);

    return 0;
}

void displayArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void bubbleSort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
