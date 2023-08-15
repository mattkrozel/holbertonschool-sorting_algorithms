#include "sort.h"

/**
 * bubble_sort - sorts an array of ints
 * @array: pointer to an array of ints
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, counter;
	int temp;

	if (size < 2)
		return;
	for (counter = 0; size - 1 != counter;)
	{
		counter = 0;
		for (i = 0; i + 1 != size; i++)
		{
			if (array[i + 1] < array[i])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
			else
				counter++;
		}
	}
}
