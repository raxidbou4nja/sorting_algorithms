#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - sorts an array of integers in ascending order using
 * the Counting Sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *output = NULL, max_value = 0, *count_arr = NULL;
	size_t i;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}
	count_arr = malloc((max_value + 1) * sizeof(int));
	if (count_arr == NULL)
		return;

	for (i = 0; i <= (size_t)max_value; i++)
		count_arr[i] = 0;
	for (i = 0; i < size; i++)
		count_arr[array[i]]++;
	for (i = 1; i <= (size_t)max_value; i++)
		count_arr[i] += count_arr[i - 1];

	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count_arr);
		return;
	}
	for (i = 0; i < size; i++)
	{
		output[count_arr[array[i]] - 1] = array[i];
		count_arr[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(count_arr, max_value + 1);
	free(count_arr);
	free(output);
}
