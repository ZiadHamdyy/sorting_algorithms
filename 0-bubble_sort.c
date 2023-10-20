#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers.
 * @array: array to be sorted.
 * @size: number of elements in the array.
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t first, sec;
	int temp;

	if (array == NULL || size == 0)
		return;

	for (first = 0; first < size - 1; first++)
	{
		int swapped = 0;

		for (sec = 0; sec < size - first - 1; sec++)
		{
			if (array[sec] > array[sec + 1])
			{
				temp = array[sec];
				array[sec] = array[sec + 1];
				array[sec + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}

/**
 * swap_integers - Swap two integers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 *
 * Return: void
 */
void swap_integers(int *x, int *y)
{
	int z;

	z = *x;
	*x = *y;
	*y = z;
}
