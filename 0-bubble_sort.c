#include "sort.h"

/**
 * bubble_sort - Sorts an array using Bubble Sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * Return: Void
 **/

void bubble_sort(int *array, size_t size)
{
	int m;
	size_t x : size_t y;

	if (size < 2)
		return;
	for (x = 0; x < size - 1; x++)
	{
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				m = array[y];
				array[y] = array[y + 1];
				array[y + 1] = m;
				print_array(array, size);
			}
		}
	}
}
