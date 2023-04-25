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
 * put_string - puts string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars puted
 */
int put_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = STRING_IS_NULL;

	j = pad = _stringlength(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->flag_minus)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += put_s(str);
	}
	while (j++ < params->width)
		sum += _putchar(pad_char);
	if (!params->flag_minus)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += put_s(str);
	}
	return (sum);
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
 * put_S - custom format specifier
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars puted
 */
int put_STR(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (put_s(STRING_IS_NULL));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += put_s(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
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
