#include <stdio.h>

// Function prototypes
int getMax(int a[], int n);
void countSort(int a[], int n);
void display(int a[], int n);

int main() {
    int n, i;

    printf("\nEnter the value of n: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter Elements of Array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Before Sorting, Array Elements Are:\n");
    display(a, n);

    countSort(a, n);

    printf("\nAfter Sorting, Array Elements Are:\n");
    display(a, n);

    return 0;
}

int getMax(int a[], int n) {
    int i, k = 0;
    for (i = 1; i < n; i++) {
        if (a[i] > k)
            k = a[i];
    }
    return k; // maximum element from the array
}

void countSort(int a[], int n) {
    int i, b[n];
    int max = getMax(a, n);
    int count[max + 1];

    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (i = 0; i < n; i++) {
        count[a[i]]++;
    }

    for (i = 1; i <= max; i++) {
        count[i] = count[i] + count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        b[--count[a[i]]] = a[i];
    }

    for (i = 0; i < n; i++) {
        a[i] = b[i];
    }
}

void display(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}
