#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer to the string
 *
 * Return: void
 */
void rev_string(char *s)
{
	int i = 0, j = 0;
	char temp;

	/* نحسب الطول */
	while (s[j] != '\0')
	{
		j++;
	}
	j--; /* آخر index */

	/* نعكس النص */
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}
