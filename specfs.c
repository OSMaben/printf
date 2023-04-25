#include "main.h"

/**
 * hold_specifier - finds the format func
 * @s: the format string
 *
 * Return: the number of bytes puted
 */
int (*hold_specifier(char *s))(va_list ap, params_t *params)
{
	spec_t specifiers[] = {
		{"c", put_char},
		{"d", put_int},
		{"i", put_int},
		{"s", put_string},
		{"%", put_percent},
		{"b", put_binary},
		{"o", put_octal},
		{"u", put_unsigned},
		{"x", put_hexadicimal},
		{"X", put_HEXADICIMAL},
		{"p", put_addrss},
		{"S", put_STR},
		{"r", put_rev},
		{"R", rotate_f},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].spec)
	{
		if (*s == specifiers[i].spec[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}




/**
 * put_from_to - puts a range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 *
 * Return: number bytes puted
 */
int put_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * put_rev - puts string in reverse
 * @ap: string
 * @params: the parameters struct
 *
 * Return: number bytes puted
 */
int put_rev(va_list ap, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * rotate_f - puts string in roatation
 * @ap: string
 * @params: the parameters struct
 *
 * Return: number bytes puted
 */
int rotate_f(va_list ap, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
