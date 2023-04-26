#include "main.h"



/**
 * hold_put_func - finds the format func
 * @s: the format string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: the number of bytes puted
 */
int hold_put_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = hold_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * hold_flag - finds the flag func
 * @s: the format string
 * @params: the parameters struct
 *
 * Return: if flag was valid
 */
int hold_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->flag_plus = 1;
			break;
		case ' ':
			i = params->flag_space = 1;
			break;
		case '#':
			i = params->hash_flag = 1;
			break;
		case '-':
			i = params->flag_minus = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * hold_modifier - finds the modifier func
 * @s: the format string
 * @params: the parameters struct
 *
 * Return: if modifier was valid
 */
int hold_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = params->short_modif = 1;
		break;
	case 'l':
		i = params->long_modif = 1;
		break;
	}
	return (i);
}

/**
 * hold_width - holds the width from the format string
 * @s: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *hold_width(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_digit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
