#include "sort.h"

/**
 * shell_sort - Shell sort algorithm
 * @array: Array.....
 * @size: nums of array..
 *
 * Return: Null
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, gap;

	if (array == NULL || size == 0)
		return;
	{
		gap = 1;
		while (gap < size)
			gap = gap * 3 + 1;
		gap = (gap - 1) / 3;
		for (; gap > 0; gap = (gap - 1) / 3)
		{
			for (i = gap; i < size; i++)
			{
				temp = array[i];
				for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
					array[j] = array[j - gap];
				array[j] = temp;
			}
			print_array(array, size);
		}
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
