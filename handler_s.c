#include "main.h"

/**
 * put_char - printf characters
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars puted
 */
int put_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if (params->flag_minus)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->flag_minus)
		sum += _putchar(ch);
	return (sum);
}

/**
 * put_int - puts integer
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars puted
 */
int put_int(va_list ap, params_t *params)
{
	long l;

	if (params->long_modif)
		l = va_arg(ap, long);
	else if (params->short_modif)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (put_number(convert(l, 10, 0, params), params));
}

/**
 * put_percent - puts string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars puted
 */
int put_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * hold_precision - DISplay precision from a formatted string
 * @p: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *hold_precision(char *p, params_t *params, va_list ap)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_digit(*p))
			d = d * 10 + (*p++ - '0');
	}
	params->precision = d;
	return (p);
}
