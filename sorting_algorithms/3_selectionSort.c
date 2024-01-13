#include <stdio.h>

// Function prototypes
void selectionSort();

int a[30], n;

int main() {
    int i;

    printf("\nEnter the size of the array: ");
    scanf("%d", &n);

    printf("Enter elements of the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    selectionSort();

    printf("\nArray Elements After Sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    return 0;
}

void selectionSort() {
    int i, j, min, temp;
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
