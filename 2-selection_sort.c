#include "sort.h"
/**
 * _swap - ..........
 * @x:first element.
 * @y:second element.
 * Return:void.
 */
void _swap(int *x, int *y)
{
	int z;

	z = *x;
	*x = *y;
	*y = z;
}
/**
 * selection_sort - ..........
 * @array:unsorted array.
 * @size:size of the array.
 * Return:void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (array == NULL || size == 0)
		return;
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
		if (min != i)
		{
			_swap(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
