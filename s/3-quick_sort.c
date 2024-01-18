#include "sort.h"

/**
 * lomutoPartition - sorts pivot
 * @array: The array to sort
 * @start:  start of the index
 * @end: the end of index
 * @size:  array  of size
 * Return: The index of the pivot
 */
size_t lomuto_Par(int *ar, size_t begin, size_t end, size_t len)
{
	int pivot = ar[end], p;
	int i, j;

	for (j = i = begin; j < end; j++)
	{
		if (array[j] < pivot)
		{

			if (i != j)
			{
				p = array[j];
				array[j] = array[i];
				array[i] = p;
				print_array(array, size);
			}
			i+=1;
		}
	}

	/* swap */
	p = array[i];
	array[i] = array[end];
	array[end] = p;
	print_array(array, size);
	return (i);
}

/**
 * quick_sort_rec - sorts an array using the quick sort algorithm
 * @array: array to sort
 * @start: start  of index
 * @end: end of index
 * @size: array  of size
 */
void quick_sort_rec(int *array, int start, int end, size_t size)
{
	size_t idx_part;

	/* base */
	if (end < start)
		return;

	idx_part = lomutoPartition(array, start, end, size);

	quick_sort_rec(array, start, idx_part - 1, size);
	quick_sort_rec(array, idx_part + 1, end, size);
}

/**
 * quick_sort - sorts a list using the quick sort algotithm
 * @array: The array to  sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_rec(array, 0, size - 1, size);
}
