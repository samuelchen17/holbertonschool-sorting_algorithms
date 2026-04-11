#include "sort.h"
#include <stdio.h>

int partition(int array[], int low, int high, size_t size);
void quicksort_recursion(int array[], int low, int high, size_t size);
void swap(int *a, int *b, int *array, size_t size);
void print_array(const int *array, size_t size);

/**
 * swap - swap two integers in place
 * @a: first integer
 * @b: second integer
 * @array: pointer to array of integers
 * @size: number of elements in the array
 */
void swap(int *a, int *b, int *array, size_t size)
{
int tmp = 0;

if (a == b)
return;

tmp = *a;
*a = *b;
*b = tmp;

print_array(array, size);
}

/**
 * quicksort_recursion - recursively sorts an array using Quick sort
 * @array: pointer to array of integers
 * @low: starting index of subarray
 * @high: end index of subarray
 * @size: number of elements in the array
 */
void quicksort_recursion(int array[], int low, int high, size_t size)
{
if (low < high)
{
int pivot_index = partition(array, low, high, size);
/* left portion */
quicksort_recursion(array, low, pivot_index - 1, size);
/* right portion */
quicksort_recursion(array, pivot_index + 1, high, size);
}
}

/**
 * partition - partitions array using Lomuto
 * @array: pointer to array of integers
 * @low: starting index of subarray
 * @high: end index of subarray
 * @size: number of elements in the array
 *
 * Return: the final index of the pivot
 */
int partition(int array[], int low, int high, size_t size)
{
int pivot_value = array[high];

int i = low, int j = 0;

for (j = low; j < high; j++)
{
if (array[j] < pivot_value)
{
swap(&array[i], &array[j], array, size);
i++;
}
}

swap(&array[i], &array[high], array, size);

/* return final position of pivot */
return (i);
}

/**
 * quick_sort - quick sort an array in ascending order
 * @array: pointer to array of integers
 * @size: number of elements in the array
 */

void quick_sort(int *array, size_t size)
{
/* edgecase */
if (!array || size < 2)
return;

quicksort_recursion(array, 0, size - 1, size);
}
