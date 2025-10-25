#include "main.h"

/**
 * puts_half - prints the second half of a string
 * @str: pointer to the string
 *
 * Return: void
 */
void puts_half(char *str)
{
	int len = 0, start, i;

	/* نحسب طول النص */
	while (str[len] != '\0')
	{
		len++;
	}

	/* نحدد بداية الطباعة */
	if (len % 2 == 0)
		start = len / 2;
	else
		start = (len + 1) / 2;

	/* نطبع من النص إلى النهاية */
	for (i = start; i < len; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
