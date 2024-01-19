#include "sort.h"

void merge(int *array, size_t left, size_t middle, size_t right)
{
    size_t i, j, k;
    size_t n1 = middle - left + 1;
    size_t n2 = right - middle;

    int *left_array = malloc(sizeof(int) * n1);
    int *right_array = malloc(sizeof(int) * n2);

    if (!left_array || !right_array)
    {
        free(left_array);
        free(right_array);
        return;
    }

    for (i = 0; i < n1; i++)
        left_array[i] = array[left + i];

    for (j = 0; j < n2; j++)
        right_array[j] = array[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (left_array[i] <= right_array[j])
        {
            array[k] = left_array[i];
            i++;
        }
        else
        {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = left_array[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = right_array[j];
        j++;
        k++;
    }

    free(left_array);
    free(right_array);
}

void merge_sort_recursive(int *array, size_t left, size_t right)
{
    if (left < right)
    {
        size_t middle = left + (right - left) / 2;

        printf("Merging...\n[left]: ");
        print_array(array + left, middle - left + 1);
        printf("[right]: ");
        print_array(array + middle + 1, right - middle);
        
        merge_sort_recursive(array, left, middle);
        merge_sort_recursive(array, middle + 1, right);

        printf("[Done]: ");
        print_array(array + left, right - left + 1);

        merge(array, left, middle, right);
    }
}

void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    merge_sort_recursive(array, 0, size - 1);
}
