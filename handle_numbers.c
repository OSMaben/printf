#include "main.h"

/**
 * _digit -a function that check if the character is a digit
 * @c: the character to be checked
 *
 * Return: 1 if digit, 0 id not
 */
int _digit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _stringlength - returns the length of a string
 * @s: length of the string
 *
 * Return: length of the string
 */
int _stringlength(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * put_number - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int put_number(char *str, params_t *params)
{
	unsigned int i = _stringlength(str);
	int neggats = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neggats)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neggats)
		*--str = '-';

	if (!params->flag_minus)
		return (right_shift(str, params));
	else
		return (left_shift(str, params));
}

/**
 * right_shift - print right shift digits
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int right_shift(char *str, params_t *params)
{
	unsigned int n = 0, neggats, nigative, i = _stringlength(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->flag_minus)
		pad_char = '0';
	neggats = nigative = (!params->unsign && *str == '-');
	if (neggats && i < params->width && pad_char == '0' && !params->flag_minus)
		str++;
	else
		neggats = 0;
	if ((params->flag_plus && !nigative) ||
		(!params->flag_plus && params->flag_space && !nigative))
		i++;
	if (neggats && pad_char == '0')
		n += _putchar('-');
	if (params->flag_plus && !nigative && pad_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->flag_plus && params->flag_space && !nigative &&
		!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (neggats && pad_char == ' ')
		n += _putchar('-');
	if (params->flag_plus && !nigative && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->flag_plus && params->flag_space && !nigative &&
		!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += put_s(str);
	return (n);
}

/**
 * left_shift -print left shift digits
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int left_shift(char *str, params_t *params)
{
	unsigned int n = 0, neggats, nigative, i = _stringlength(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->flag_minus)
		pad_char = '0';
	neggats = nigative = (!params->unsign && *str == '-');
	if (neggats && i < params->width && pad_char == '0' && !params->flag_minus)
		str++;
	else
		neggats = 0;

	if (params->flag_plus && !nigative && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->flag_space && !nigative && !params->unsign)
		n += _putchar(' '), i++;
	n += put_s(str);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
