void radix_sort(int *array, size_t size)
{
	int l = size;
	int p, x, i, j;
	while (j == 0)
	{
		j = 1;
		for (x = 0; x < l; x++)
		{ printf("h");
			if ((array[i] % 10) > (array[i + 1] % 10))
				p = array[i];
			array[i] = array[i + 1];
			array[i + 1] = p;
			j = 0;
		} l--;
	}
	print_array(array, size);
}

