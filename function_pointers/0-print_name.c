#include "function_pointers.h"

/**
 * print_name - prints a name using a function pointer
 * @name: string name
 * @f: function pointer to print format
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
