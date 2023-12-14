#include "sort.h"

/**
 * swap_ints - To swap two integers in an array.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - To sort an array of integers in ascending order.
 * @array: The array of integers to sort.
 * @size: Size of the array.
 *
 * Description: To print the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (x = 0; x < len - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				swap_ints(array + x, array + x + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
