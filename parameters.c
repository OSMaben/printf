#include "main.h"

/**
 * init_params - clears struct fields and reset buf
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: void
 */
void init_params(params_t *params, va_list ap)
{
	params->unsign = 0;

	params->flag_plus = 0;
	params->flag_space = 0;
	params->hash_flag = 0;
	params->zero_flag = 0;
	params->flag_minus = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->short_modif = 0;
	params->long_modif = 0;
	(void)ap;
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
