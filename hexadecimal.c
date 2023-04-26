#include "main.h"
/**
 * put_hexadicimal - hes in lowercase
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes puted
 */
int put_hexadicimal(va_list ap, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->long_modif)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->short_modif)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CON_UNSIGNED | LOWERCASE, params);
	if (params->hash_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += put_number(str, params));
}

/**
 * put_HEXADICIMAL - hex in uppercase
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes puted
 */
int put_HEXADICIMAL(va_list ap, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->long_modif)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->short_modif)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CON_UNSIGNED, params);
	if (params->hash_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += put_number(str, params));
}


/**
 * convert - this is a clone of the function atoi
 * @num: number
 * @base: base
 * @flags: argument flags
 * @params: paramater struct
 *
 * Return: string
 */

char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CON_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CON_UNSIGNED ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
