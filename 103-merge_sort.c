#include "sort.h"


/**
 * merge - .........
 * @array:unsorted array.
 * @left:the s first array.
 * @left_size:the size of left array.
 * @right:the second.
 * @right_size: the size of right array.
 * @size:size of the array.
 * Return:void.
 */

void merge(int *array, int *left, int left_size, int *right,
		int right_size, size_t size)
{
	int i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < left_size)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		array[k] = right[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - bla bla...
 * @array: array.
 * @size:size of the array.
 * Return:void.
 */

void merge_sort(int *array, size_t size)
{
	int middle = size / 2;
	int *left = array;
	int *right = array + middle;
	int *temp;
	size_t i;

	if (size <= 1)
		return;

	merge_sort(left, middle);
	merge_sort(right, size - middle);
	temp = (int *)malloc(size * sizeof(int));
	if (temp == NULL)
		exit(1);

	merge(temp, left, middle, right, size - middle, size);

	for (i = 0; i < size; i++)
	{
		array[i] = temp[i];
	}
	free(temp);
}
