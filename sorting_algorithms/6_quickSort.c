#include <stdio.h>

// Function prototypes
int partition(int a[], int lb, int ub);
void quicksort(int a[], int lb, int ub);
void display(int a[], int n);

int main() {
    int a[20], n, i;

    printf("\nEnter the value of n: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nArray Elements Before Sorting:\n");
    display(a, n);

    quicksort(a, 0, n - 1);

    printf("\nArray Elements After Sorting:\n");
    display(a, n);

    return 0;
}

int partition(int a[], int lb, int ub) {
    int pivot, low, high, temp;
    pivot = a[lb];
    low = lb;
    high = ub;

    while (low < high) {
        while (a[low] <= pivot) {
            low++;
        }
        while (a[high] > pivot) {
            high--;
        }
        if (low < high) {
            int temp = a[low];
            a[low] = a[high];
            a[high] = temp;
        }
    }

    temp = a[lb];
    a[lb] = a[high];
    a[high] = temp;

    return high;
}

void quicksort(int a[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition(a, lb, ub);
        quicksort(a, lb, loc - 1);
        quicksort(a, loc + 1, ub);
    }
}

void display(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}
