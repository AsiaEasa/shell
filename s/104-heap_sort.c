#include "sort.h"

#define top(i) ((i / 2) - 1)
#define le_ft(i) ((2 * i) + 1)
#define ri_ght(i) ((2 * i) + 2)


/**
 * _heap -Function use in the Heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @B: The index of the base row of the tree.
 * @top: The top node of the tree.
 */
void _heap(int *array, size_t size, size_t B, size_t top)
{
	int p, l, r, big;

	l = le_ft(top);
	r = ri_ght(top);
	big = top;

	switch (array[r] > array[big]) {
		case 1:
			switch ((int)B > r) {
				case 1:
					big = r;
			}
			break;
	}
	switch (array[l] > array[big]) {
		case 1:
			switch ((int)B > l) {
				case 1:
					big = l;
			}
			break;
	}
	if (top != (size_t)big)
	{
		p = array[top];
		array[top] = array[big];
		array[big] = p;
		print_array(array, size);
		_heap(array, size, B, big);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i, p;

	if (!array || !size || size < 2)
		return;

	i = top(size);
	while (i >= 0)
		_heap(array, size, size, i--);


	i = top(size * 2);
	while (i > 0)
	{
		p = array[0];
		array[0] = array[i];
		array[i] = p;
		print_array(array, size);
		_heap(array, size, i, 0);
		i -= 1;
	}
}
