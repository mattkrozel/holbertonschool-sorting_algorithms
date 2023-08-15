#include "sort.h"
#include <stdlib.h>
void sort(int *array, size_t begin, size_t size, size_t);
int check(int *array, size_t begin, size_t end);
int swap(int *, size_t, size_t);

/**
 * quick_sort - sorts array of ints
 * @array: array of ints
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	size_t begin;

	begin = 0;
	if (size < 2 || array == NULL)
		return;
	size = size - 1;
	sort(array, begin, size, size + 1);
}

/**
 * sort - does actual sorting
 * @begin: beginning
 * @array: array of ints
 * @end: end
 * @og: original size
 */
void sort(int *array, size_t begin, size_t end, size_t og)
{
	size_t i, j;
	int p, flag, c;

	p = array[end];
	j = begin;
	i = j - 1;
	flag = 0;

	for (j = begin; j < end; j++)
	{
		if (array[j] <= p)
		{
			i++;
			flag = swap(array, j, i, og);
		}
	}
	i++;
	flag = swap(array, j, i, og);
	if (flag == 0)
	{
		c = check(array, begin, end);
		if (c == 1)
			sort(array, begin, end - 1, og);
	}
	else
	{
		sort(array, begin, i, og);
		sort(array, i, end, og);
	}
}

/**
 * swap - swaps numbers in array
 * @array: array of ints
 * @i: lower bound of array
 * @j: upper bound of array
 * @og: original size
 * Return: 1 when swap happens, 0 else
 */
int swap(int *array, size_t i, size_t j, size_t og)
{
	int temp;

	if (j != i)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, og);
		return (1);
	}
	return (0);
}

/**
 * check - checks if array has been sorted
 * @array: array of ints
 * @begin: lower bound of array
 * @end: upper bound of array
 * Return: 1 if array is not sorted
 */
int check(int *array, size_t begin, size_t end)
{
	size_t i;

	for (i = begin; i < end; i++)
	{
		if (array[i] > array[i + 1])
			return (1);
	}
	return (0);
}
