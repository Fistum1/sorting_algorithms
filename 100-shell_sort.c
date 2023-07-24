#include "sort.h"

/**
*swap - A position of two elements into an array
*@array: An array
*@item1: An array of elements
*@item2: AN array of elements
*/
void swap(int *array, int item1, int item2)
{

	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 * shell_sort - A function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @size: A size of the array
 * @array: A list with numbers
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, a, index = 0;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (a = gap; a < size; a++)
			for (index = a; index >= gap &&
			 (array[index] < array[index - gap]); index -= gap)
				swap(array, index, index - gap);
		print_array(array, size);
		gap /= 3;
	}
}
