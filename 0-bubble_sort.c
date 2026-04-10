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
 * bubble_sort - bubble sort an array in ascending order
 * @array: pointer to array of integers
 * @size: number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
size_t i = 0, j = 0;
int swapped = 0;

/* edge case */
if (!array || size < 2)
return;

for (i = 0; i < size - 1; i++)
{
swapped = 0;

for (j = 0; j < size - i - 1; j++)
{
if (array[j] > array[j + 1])
{
swap(&array[j], &array[j + 1]);

swapped = 1;

print_array(array, size);
}
}

if (!swapped)
break;
}
}
