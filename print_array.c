#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - To print an array of integers
 *
 * @array: An array to be printed
 * @size: The number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	for (size_t j = 0; array && j < size; ++j)
	{
	if (j > 0)
		printf(", ");
	printf("%d", array[j]);
	}
	printf("\n");
}
