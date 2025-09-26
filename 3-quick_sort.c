#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @array: the array
 * @i: index of first element
 * @j: index of second element
 */
void swap(int *array, int i, int j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/**
 * lomuto_partition - partitions array using Lomuto scheme
 * @array: the array
 * @first: first index
 * @last: last index
 * @size: size of the array
 * Return: partition index
 */
int lomuto_partition(int *array, int first, int last, size_t size)
{
	int pivot = array[last];
	int current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}

/**
 * qs - recursive quicksort function
 * @array: the array
 * @first: first index
 * @last: last index
 * @size: array size
 */
void qs(int *array, int first, int last, size_t size)
{
	int position;

	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);
		qs(array, first, position - 1, size);
		qs(array, position + 1, last, size);
	}
}

/**
 * quick_sort - sorts an array using Quick sort algorithm
 * @array: the array
 * @size: number of elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
