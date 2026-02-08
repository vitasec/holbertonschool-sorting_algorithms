#include "sort.h"
#include <stddef.h>

/**
 * selection_sort - sorts an array of integers in ascending order using the
 * Selection sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	 size_t i, j, i_min;
	 int temp;

	for (j = 0; j < size; j++)
	{
		i_min = j;

		for (i = j + 1; i < size; i++)
		{
			if (array[i] < array[i_min])
				i_min = i;
		}

		if (i_min != j)
		{
			temp = array[j];
			array[j] = array[i_min];
			array[i_min] = temp;
			print_array(array, size);
		}
	}
}
