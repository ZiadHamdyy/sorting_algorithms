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
 * heapify - ..........
 * @array:unsorted array.
 * @n:the root.
 * @i:the position for check for max heap or min heap.
 * @size:the size of the array.
 * Return:void.
 */
void heapify(int *array, int n, int i, size_t size)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int max = i;

	if (left < n && array[left] > array[max])
		max = left;
	if (right < n && array[right] > array[max])
		max = right;
	if (max != i)
	{
		_swap(&array[i], &array[max]);
		print_array(array, size);
		heapify(array, n, max, size);
	}
}

/**
 * BuildHeap - .............
 * @array:unsorted array.
 * @n:the root.
 * @size:the size of the array.
 * Return:void.
 */
void BuildHeap(int *array, int n, size_t size)
{
	int i;

	for (i = n / 2 - 1; i >= 0; i--)
		heapify(array, n, i, size);
}
/**
 * heap_sort - .........
 * @array:unsorted array.
 * @size:the size of the array.
 * Return:void.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	BuildHeap(array, size, size);
	for (i = size - 1; i > 0; i--)
	{
		_swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
