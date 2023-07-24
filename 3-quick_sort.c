#include "sort.h"
/**
*swap - A position of two elements into an array
*@array: An array
*@item1: An array of elements
*@item2: An array of elements
*/
void swap(int *array, size_t item1, size_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 *lomuto_partition - The lomuto partition sorting scheme implementation
 *@array: An array
 *@first: The first array element
 *@last: The last array element
 *@size: The size of an array
 *Return: It returns the position of the last element sorted
 */
int lomuto_partition(int *array, size_t first, size_t last, size_t size)
{
	int pivot = array[last];
	size_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}
/**
 *qs - A qucksort algorithm implementation
 *@array: An array
 *@first: The first array element
 *@last: The last array element
 *@size: An array of size
 */
void qs(int *array, size_t first, size_t last, int size)
{
	size_t position = 0;


	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		qs(array, first, position - 1, size);
		qs(array, position + 1, last, size);
	}
}
/**
 *quick_sort - It prepares the terrain to quicksort algorithm
 *@array: An array
 *@size: An array of sizes
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
