#include "sort.h"
/**
 * selection_sort - The function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: A size of the array
 * @array: A list with numbers
 */
void selection_sort(int *array, size_t size)
{
	size_t a, index;
	int tmp, swap, flag = 0;

	if (array == NULL)
		return;
	for (a = 0; a < size; a++)
	{
		tmp = a;
		flag = 0;
		for (index = a + 1; index < size; index++)
		{
			if (array[tmp] > array[index])
			{
				tmp = index;
				flag += 1;
			}
		}
		swap = array[a];
		array[a] = array[tmp];
		array[tmp] = swap;
		if (flag != 0)
			print_array(array, size);
	}
}
