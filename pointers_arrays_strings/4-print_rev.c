#include "main.h"

/**
 * print_rev - prints a string in reverse followed by a new line
 * @s: pointer to the string
 *
 * Return: void
 */
void print_rev(char *s)
{
	int len = 0;
	int i;

	/* أولاً نحسب طول النص */
	while (s[len] != '\0')
	{
		len++;
	}

	/* نطبع بالعكس */
	for (i = len - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
