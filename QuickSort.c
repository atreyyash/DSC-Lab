#include <stdio.h>

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int partition(int *a, int s, int e)
{
    int pivot = a[e];
    int i = s - 1;

    for (int j = s; j <= e - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    int t = a[i + 1];
    a[i + 1] = a[e];
    a[e] = t;
    return (i + 1);
}

void QuickSort(int *a, int s, int e)
{
    if (s > e)
    {
        return;
    }

    int p = partition(a, s, e);
    QuickSort(a, s, p - 1);
    QuickSort(a, p + 1, e);
}

int main()
{
    int a[] = {10, 5, 1, 4, 6, 2, 9};
    int n = sizeof(a) / sizeof(int);

    printf("Before Sorting : ");
    printArray(a, n);

    QuickSort(a, 0, n - 1);

    printf("After Sorting : ");
    printArray(a, n);

    return 0;
}