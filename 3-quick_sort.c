#include "sort.h"

/**
 * swap_items - swaps two integers in an array and prints the array
 * @array: the array to modify
 * @size: the size of the array
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap_items(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - partitions the array using the Lomuto scheme
 * @array: the array to partition
 * @size: the total size of the array (for printing)
 * @low: the starting index of the partition
 * @high: the ending index of the partition (the pivot)
 *
 * Return: the final index of the pivot
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap_items(array, size, &array[i], &array[j]);
			i++;
		}
	}
	swap_items(array, size, &array[i], &array[high]);
	return (i);
}

/**
 * quick_recursion - recursive helper for quick_sort
 * @array: the array to sort
 * @size: the total size of the array
 * @low: starting index
 * @high: ending index
 */
void quick_recursion(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int p_idx = lomuto_partition(array, size, low, high);

		quick_recursion(array, size, low, p_idx - 1);
		quick_recursion(array, size, p_idx + 1, high);
	}
}

/**
 * quick_sort - sorts an array of integers using Quick sort
 * @array: the array to sort
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_recursion(array, size, 0, size - 1);
}
