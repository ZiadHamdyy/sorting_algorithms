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
 * lomutoPartition - ..........
 * @array:unsorted array.
 * @start:the start of the array.
 * @end:the end of the array.
 * @size:size of the array.
 * Return:part.
 */
int lomutoPartition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int i = start - 1, j;

	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				_swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[end])
	{
		_swap(&array[i + 1], &array[end]);
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quickSort - .......
 * @array:unsorted array.
 * @start:the start of the array.
 * @end:the end of the array.
 * @size:size of the array.
 * Return:void.
 */
void quickSort(int *array, int start, int end, size_t size)
{
	int pivotIndex;

	if (start < end)
	{
		pivotIndex = lomutoPartition(array, start, end, size);
		quickSort(array, start, pivotIndex - 1, size);
		quickSort(array, pivotIndex + 1, end, size);
	}
}
/**
 * quick_sort - .........
 * @array:unsorted array.
 * @size:size of the array.
 * Return:void.
 */
void quick_sort(int *array, size_t size)
{
		quickSort(array, 0, size - 1, size);
}
