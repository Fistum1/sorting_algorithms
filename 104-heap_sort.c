#include "sort.h"
#include <stdio.h>

/**
 * swap - A utility function to swap to integers
 * @a: An integer a
 * @b: An integer b
 **/
void swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}

/**
 * maxHeapify - The main function to heapify a Max Heap. The function
 * assumes that everything under given root (element at index idx)
 * is already heapified
 * @array: An array
 * @size: A size of the array for print
 * @idx: An index
 * @n: A size of the array to run
 */
void maxHeapify(int *array, size_t size, int idx, size_t n)
{
	int largest = idx;		 /* Initialize largest as root*/
	int left = 2 * idx + 1;	 /* left = (idx << 1) + 1*/
	int right = 2 * idx + 2; /* right = (idx + 1) << 1*/

	/* See if left child of root exists and is greater than root*/
	if (left < (int)n && array[left] > array[largest])
		largest = left;

	/**
	 * Which see if right child of root exists and is greater than
     *the largest so far
	 */
	if (right < (int)n && array[right] > array[largest])
		largest = right;

	/* Change root, if needed*/
	if (largest != idx)
	{
		swap(&array[idx], &array[largest]);
		print_array(array, size);
		maxHeapify(array, size, largest, n);
	}
}

/**
 * heap_sort -  The main function to sort an array of given size
 * @array: An array to sort
 * @size: A size of the array
 **/
void heap_sort(int *array, size_t size)
{
	int a;
	/**
	 * It starts from bottommost and rightmost internal mode and heapify all
     * An internal modes in bottom up way
	 */
	if (array == '\0' || size < 2)
		return;

	for (a = (size - 2) / 2; a >= 0; --a)
		maxHeapify(array, size, a, size);

	/**
	* It repeats following steps while heap size is greater than 1.
    * The last element in max heap will be the minimum element
	*/
	for (a = (size - 1); a > 0; --a)
	{
		/**
		* The largest item in Heap is stored at the root. Replace
		*it with the last item of the heap followed by reducing the
		*size of heap by 1.
		*/
		swap(&array[0], &array[a]);
		print_array(array, size);

		/* Finally, heapify the root of tree.*/
		maxHeapify(array, size, 0, a);
	}
}
