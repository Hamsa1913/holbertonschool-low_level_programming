#include "main.h"
#include <stdlib.h>

/**
 * _strdup - duplicates a string into a newly allocated memory
 * @str: source string to duplicate (may be NULL)
 *
 * Return: pointer to duplicated string on success,
 *         or NULL if str is NULL or memory allocation fails
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len = 0;

	if (str == 0)
		return (0);

	while (str[len] != '\0')
		len++;

	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup == 0)
		return (0);

	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[len] = '\0';

	return (dup);
}
