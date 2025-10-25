#include "main.h"

/**
 * _strncat - concatenates two strings using at most n bytes from src
 * @dest: pointer to destination string
 * @src: pointer to source string
 * @n: number of bytes to use from src
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	/* نلقى نهاية dest */
	while (dest[i] != '\0')
	{
		i++;
	}

	/* ننسخ من src بحد أقصى n أحرف */
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';

	return (dest);
}
