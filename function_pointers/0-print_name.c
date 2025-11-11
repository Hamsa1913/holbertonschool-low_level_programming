#include "function_pointers.h"

/**
 * print_name - calls a function to print a name
 * @name: pointer to string name
 * @f: pointer to function that takes (char *) and returns void
 *
 * Description: does nothing if name or f is NULL
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
