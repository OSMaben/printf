#include "main.h"

/**
 * put_s - A FUNCtion that prints a string with a new line
 * @string: the string to be printed
 *
 * Return:length of the string
 */
int put_s(char *string)
{
	char *a = string;

	while (*string)
		_putchar(*string++);
	return (string - a);
}

/**
 * _putchar - write any character to standard output
 * @c: The character to print
 *
 * Return:1 on success, 0 on failure
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUFFER_SIZE];

	if (c == BUFFER_SH || i >= OUTPUT_BUFFER_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUFFER_SH)
		buf[i++] = c;
	return (1);
}
