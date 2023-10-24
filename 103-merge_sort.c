#include "sort.h"

void auxarry_merge(int *auxarry, int *buf, size_t front, size_t centre,
		size_t back);
void loop_merge_sort(int *auxarry, int *buf, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 *  * auxarray_merge - Merges two subarrays into a single sorted array
 *  @auxarry: Pointer to the auxiliary array containing
 *   elements to be merged
 *    * @buf: Pointer to the buffer array for temporary storage during merging
 *     * @front: Index of the start of the first subarray
 *      * @centre: Index marking the end of the first subarray and
 *      start of the second subarray
 *       * @back: Index marking the end of the second subarray
 *        * Return: Void
 *
 */

void auxarry_merge(int *auxarry, int *buf, size_t front, size_t centre,
		size_t back)
{
	size_t x, y, z = 0;

	printf("Merging...\n[left]: ");
	print_array(auxarry + front, centre - front);

	printf("[right]: ");
	print_array(auxarry + centre, back - centre);

	for (x = front, y = centre; x < centre && y < back; z++)
		buf[z] = (auxarry[x] < auxarry[y]) ? auxarry[x++] : auxarry[y++];
	for (; x < centre; x++)
		buf[z++] = auxarry[x];
	for (; y < back; y++)
		buf[z++] = auxarry[y];
	for (x = front, z = 0; x < back; x++)
		auxarry[x] = buf[z++];

	printf("[Done]: ");
	print_array(auxarry + front, back - front);
}

/**
 *  * loop_merge_sort - Sorts a subarray of integers in ascending order
 *  using Merge Sort algorithm
 *   * @auxarry: Pointer to the auxiliary array containing elements
 *   to be sorted
 *    * @buf: Pointer to the buffer array for temporary storage during merging
 *     * @front: Index of the start of the subarray to be sorted
 *      * @back: Index marking the end of the subarray to be sorted
 *       * Return: Void
 *
 */

void loop_merge_sort(int *auxarry, int *buf, size_t front, size_t back)
{
	size_t centre;

	if (back - front > 1)
	{
		centre = front + (back - front) / 2;
		loop_merge_sort(auxarry, buf, front, centre);
		loop_merge_sort(auxarry, buf, centre, back);
		auxarry_merge(auxarry, buf, front, centre, back);
	}
}

/**
 *  * merge_sort - Sorts an array of integers in ascending order using
 *  Merge Sort algorithm
 *   * @array: Pointer to the array to be sorted
 *    * @size: Size of the array
 *     * Return: Void
 *
 */

void merge_sort(int *array, size_t size)
{
	int *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	loop_merge_sort(array, buf, 0, size);

	free(buf);
}
