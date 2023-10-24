#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using
 * the Counting sort algorithm.
 * @array: array to be sorted.
 * @size: size of an array.
 */
void counting_sort(int *array, size_t size)
{
	int max = array[0];
	int i, *counting_array, j = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	counting_array = (int *)malloc(sizeof(int) * (max + 1));

	if (counting_array == NULL)
		return;

	for (i = 0; i <= max; i++)
		counting_array[i] = 0;

	for (i = 0; i < (int)size; i++)
		counting_array[array[i]]++;

	print_array(counting_array, max + 1);

	for (i = 0; i <= max; i++)
	{
		while (counting_array[i] > 0)
		{
			array[j] = i;
			j++;
			counting_array[i]--;
		}
	}

	free(counting_array);
}
