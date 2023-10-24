#include "sort.h"

/**
 *  * shell_sort - Sorts an integer array using Shell Sort algorithm
 *   * @array: Pointer to the array to be sorted
 *    * @size: Size of the array
 *     *
 *      * Return: NULL
 *       **/

void shell_sort(int *array, size_t size)
{
	unsigned int space = 1;
	unsigned int x, y;
	int tmp;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (space < size / 3)
		space = space * 3 + 1;

	while (space > 0)
	{
		for (x = space; x < size; x++)
		{
			tmp = array[x];
			y = x;
			while (y >= space && array[y - space] > tmp)
			{
				array[y] = array[y - space];
				y -= space;
			}
			array[y] = tmp;
		}
		print_array(array, size);
		space /= 3;
	}
}
