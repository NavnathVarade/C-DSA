#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct city {
    char name[20];
    int code;
} city;

int fileread(city a[20]) {
    FILE *fp;
    int i = 0;
    fp = fopen("sortcities.txt", "r");
    
    if (fp == NULL) {
        printf("File Not Exist\n");
    } else {
        while (!feof(fp)) {
            fscanf(fp, "%s%d", a[i].name, &a[i].code);
            i++;
        }
        fclose(fp);
    }

    return i-1;
}

void binarysearch(city a[], int low, int high) {
    int mid;
    char key[20];
    printf("\nEnter City: ");
    scanf("%s", key);

    while (low <= high) {
        mid = (low + high) / 2;

        if (strcmp(key, a[mid].name) == 0) {
            printf("City Code: %d\n", a[mid].code);
            exit(0);
        } else if (strcmp(key, a[mid].name) > 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("City Not In List\n");
}

int main() {
    int n;
    city a[20];

    n = fileread(a);
    
    if (n > 0) {
        for (int i = 0; i < n; i++)
            printf("%s %d\n", a[i].name, a[i].code);
        
        binarysearch(a, 0, n - 1);
    }

    return 0;
}
