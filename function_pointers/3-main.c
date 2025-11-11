#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - simple calculator
 * @argc: argument count
 * @argv: argument vector
 *
 * Usage: calc num1 operator num2
 * Return: 0 on success, exits with:
 *   98 if argc is wrong
 *   99 if operator is invalid / length != 1
 *   100 if division or modulo by 0
 */
int main(int argc, char *argv[])
{
	int a, b, result;
	int (*op_func)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	/* reject operators whose length != 1 or not in our table */
	if (argv[2][1] != '\0' || get_op_func(argv[2]) == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	/* handle division/modulo by zero */
	if ((argv[2][0] == '/' || argv[2][0] == '%') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	op_func = get_op_func(argv[2]);
	result = op_func(a, b);
	printf("%d\n", result);

	return (0);
}
