#include "sort.h"

/**
 * get_max - To get the maximum value in an array of integers.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, w;

	for (max = array[0], w = 1; w < size; w++)
	{
		if (array[w] > max)
			max = array[w];
	}

	return (max);
}

/**
 * counting_sort - To sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: To print the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, w;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (w = 0; w < (max + 1); w++)
		count[w] = 0;
	for (w = 0; w < (int)size; w++)
		count[array[w]] += 1;
	for (w = 0; w < (max + 1); w++)
		count[w] += count[w - 1];
	print_array(count, max + 1);

	for (w = 0; w < (int)size; w++)
	{
		sorted[count[array[w]] - 1] = array[w];
		count[array[w]] -= 1;
	}

	for (w = 0; w < (int)size; w++)
		array[w] = sorted[w];

	free(sorted);
	free(count);
}
