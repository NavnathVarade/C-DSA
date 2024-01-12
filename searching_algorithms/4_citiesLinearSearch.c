#include<stdio.h>
#include<string.h>

typedef struct city {
    char name[20];
    int code;
} city;

int fileread(city a[20]) {
    FILE *fp;
    int i = 0;
    fp = fopen("cities.txt", "r");

    if (fp == NULL) {
        printf("File does not exist.\n");
    } else {
        while (!feof(fp)) {
            fscanf(fp, "%s%d", a[i].name, &a[i].code);
            i++;
        }
        fclose(fp);
    }

    return i;
}

void displayRecords(city a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%s  %d\n", a[i].name, a[i].code);
}

int linearSearch(city a[], int n, char str[20]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(str, a[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int i, n;
    char key[20];
    city a[20];

    n = fileread(a);
    
    if (n > 0) {
        printf("Records from the file:\n");
        displayRecords(a, n);

        printf("Enter city to search: ");
        scanf("%s", key);

        int index = linearSearch(a, n, key);

        if (index != -1) {
            printf("\nCity Code is %d\n", a[index].code);
        } else {
            printf("\nCity is not in the list\n");
        }
    }

    return 0;
}
