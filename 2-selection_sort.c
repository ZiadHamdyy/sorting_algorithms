#include "sort.h"
/**
 */
void _swap(int *x, int *y)
{
	int z;

	z = *x;
	*x = *y;
	*y = z;
}
/**
 */
void selection_sort(int *array, size_t size)
{
	int min;
	size_t i , j;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		_swap(&array[min], &array[i]);
		print_array(array, size);
	}
}
