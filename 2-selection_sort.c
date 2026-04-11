#include "sort.h"
#include <stdio.h>

/**
 * swap - swap two integers in place
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * selection_sort - selection sort an array in ascending order
 * @array: pointer to array of integers
 * @size: number of elements in the array
 */

void selection_sort(int *array, size_t size)
{
size_t i = 0, j = 0, min_index = 0;

/* edge case */
if (!array || size < 2)
return;

/* loop to keep track of sorted elements */
for (i = 0; i < size - 1; i++)
{
min_index = i;

/* loop to find smallest value */
for (j = i + 1; j < size; j++)
{
if (array[j] < array[min_index])
min_index = j;
}

/* only swap if min_index changes */
if (min_index != i)
swap(&array[i], &array[min_index]);
}
}
