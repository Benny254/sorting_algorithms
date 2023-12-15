#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - To get the maximum value in an array of integers.
 * @array: The array of integers.
 * @size: Size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, v;

	for (max = array[0], v = 1; v < size; v++)
	{
		if (array[v] > max)
			max = array[v];
	}

	return (max);
}

/**
 * radix_counting_sort - To sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: Size of the array.
 * @sig: The significant digit to sort on.
 * @buff: The buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t v;

	for (v = 0; v < size; v++)
		count[(array[v] / sig) % 10] += 1;

	for (v = 0; v < 10; v++)
		count[v] += count[v - 1];

	for (v = size - 1; (int)v >= 0; v--)
	{
		buff[count[(array[v] / sig) % 10] - 1] = array[v];
		count[(array[v] / sig) % 10] -= 1;
	}

	for (v = 0; v < size; v++)
		array[v] = buff[v];
}

/**
 * radix_sort - To sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: The array of an integers.
 * @size: The size of an array.
 *
 * Description: To implement the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
