/*Accept n values in array from user. Accept a value x from user and use sentinel linear
search algorithm to check whether the number is present in the array or not and output the
position if the number is present.*/

#include <stdio.h>
#include <stdlib.h>
#define max 10

void generate(int a[], int n);
void Sentinelsearch(int a[], int n, int key);

int main()
{
    int a[max], key, i, n;
    printf("Enter Size of array:");
    scanf("%d", &n);
    generate(a, n);
    printf("Random elements are\n");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
        
    printf("Enter number to search: ");
    scanf("%d", &key);
    Sentinelsearch(a, n, key);
}

void generate(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand() % 100;
}

void Sentinelsearch(int a[], int n, int key)
{
    int i = 0, flag = 0;
    a[n] = key;
    while (a[i] != key)
        i++;
    if (i < n)
        printf("Searched found at index %d", i + 1);
    else
        printf("Not Found");
}