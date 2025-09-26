#include "sort.h"
#include <stdio.h>

void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Hoare partition: returns the index for partitioning */
int hoare_partition(int *array, int left, int right, size_t size)
{
    int pivot = array[left];  // pivot is left-most element
    int i = left - 1, j = right + 1;

    while (1)
    {
        do { i++; } while (array[i] < pivot);
        do { j--; } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap_ints(&array[i], &array[j]);
        print_array(array, size);
    }
}

void hoare_sort(int *array, int left, int right, size_t size)
{
    if (left < right)
    {
        int p = hoare_partition(array, left, right, size);
        hoare_sort(array, left, p, size);
        hoare_sort(array, p + 1, right, size);
    }
}

void quick_sort_hoare(int *array, size_t size)
{
    if (!array || size < 2)
        return;
    hoare_sort(array, 0, size - 1, size);
}
