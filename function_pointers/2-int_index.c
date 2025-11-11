#include "function_pointers.h"

/**
 * int_index - searches for an integer using a comparison function
 * @array: pointer to the first element of the int array
 * @size: number of elements in @array
 * @cmp: pointer to a function that compares a value; returns non-zero on match
 *
 * Return: index of the first element for which cmp does not return 0,
 *         or -1 if no match is found or if size <= 0 or on NULL pointers.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == 0 || cmp == 0 || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}
	return (-1);
}
