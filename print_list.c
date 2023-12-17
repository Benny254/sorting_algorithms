#include <stdio.h>
#include "sort.h"

/**
 * print_list -To print a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	for (int j = 0; list; ++j, list = list->next)
	{
	if (j > 0)
		printf(", ");
	printf("%d", list->n);
	}
	printf("\n");
}
