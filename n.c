void up_d1(int *array, size_t size, int start, int up, int l)
{
	int x;
	int i, j;

	i = start;
	j = start;
	if(l % 2 == 0)
	{
		for (; i < up; i++)
		{
			if (array[i] > array[i + 2])
			{
				x = array[i];
				array[i] = array[i + 2];
				array[i + 2] = x;
			}
		}
		for (; j < up - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				x = array[j];
				array[j] = array[j + 1];
				array[j + 1] = x;
			}
		}
		printf("Result [%lu/%lu] (UP):\n", 4, size);
		print_array(array, (i + 2));
	}
	else
	{
		for (; i < up; i++)
		{
			if (array[i] < array[i + 2])
			{
				x = array[i];
				array[i] = array[i + 2];
				array[i + 2] = x;
			}
		}
		for (; j < up - 1; j++)
		{
			if (array[j] < array[j + 1])
			{
				x = array[j];
				array[j] = array[j + 1];
				array[j + 1] = x;
			}
		}
		printf("Result [%lu/%lu] (UP):\n", 4, size);
		print_array(array + start, 2);
	}
}
void up_d(int *array, size_t size, int start, int up)
{
	int x;
	int i;
	int l;

	l = 2;
	i = start;

	for (; i < up - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			x = array[i];
			array[i] = array[i + 1];
			array[i + 1] = x;
		}
	}
	i++;
	printf("Result [%lu/%lu] (UP):\n", 2, size);
	print_array(array + start, 2);

	printf("Merging [%lu/%lu] (DOWN):\n", 2, size);
	print_array(array + i, 2);

	for (; i < up + 1; i++)
	{
		if (array[i] < array[i + 1])
		{
			x = array[i];
			array[i] = array[i + 1];
			array[i + 1] = x;
		}
	}

	printf("Result [%lu/%lu] (DOWN):\n", 2, size);
	print_array(array + (i - 1), 2);
	up_d1(array, size, start, up, l++);
}

void bitonic_sort(int *array, size_t size)
{
	size_t step;
	size_t l;
	l = size;
	int up, down;
	up = 2;
	if (!array || size < 2)
		return;

	for (int i = 1; l / i != 1; i *= 2)
	{
		printf("Merging [%lu/%lu] (UP):\n", (l / i), size);
		print_array(array, (l / i));
	}

	for (int i = 2; i == up; i *= 2)
	{
		up_d(array, size, 0, up);
	}

	printf("Merging [%lu/%lu] (DOWN):\n", 4, size);
	print_array(array + (up + 2), (up + 2));
	printf("Merging [%lu/%lu] (UP):\n", 2, size);
	print_array(array + 4, 2);
	up = 6;
	for (int i = 6; i == up; i *= 2)
	{
		up_d(array, size, 4, up);
	}

}

