#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer
 * @b: The second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Partition an array using Hoare scheme.
 * @array: The array to partition
 * @size: Size of the array
 * @left: Starting index
 * @right: Ending index
 *
 * Return: Partition index
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot = array[right];
	int above = left - 1, below = right + 1;

	while (1)
	{
		do {
			above++;
		} while (array[above] < pivot);

		do {
			below--;
		} while (array[below] > pivot);

		if (above >= below)
			return (below);

		swap_ints(&array[above], &array[below]);
		print_array(array, size);
	}
}

/**
 * hoare_sort - Recursively sort an array using Hoare partition.
 * @array: The array to sort
 * @size: Size of the array
 * @left: Starting index
 * @right: Ending index
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (left < right)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part);
		hoare_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort_hoare - Sort an array in ascending order using Hoare scheme.
 * @array: The array to sort
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_sort(array, size, 0, (int)size - 1);
}
