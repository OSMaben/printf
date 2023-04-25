#include "main.h"

/**
 * put_binary - puts unsigned binary number
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes puted
 */
int put_binary(va_list ap, params_t *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CON_UNSIGNED, params);
	int c = 0;

	if (params->hash_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (c += put_number(str, params));
}

/**
 * put_octal - puts unsigned octal numbers
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes puted
 */
int put_octal(va_list ap, params_t *params)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (params->long_modif)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->short_modif)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = convert(l, 8, CON_UNSIGNED, params);

	if (params->hash_flag && l)
		*--str = '0';
	params->unsign = 1;
	return (c += put_number(str, params));
}



/**
 * put_unsigned - puts unsigned numbers
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes puted
 */
int put_unsigned(va_list ap, params_t *params)
{
	unsigned long l;

	if (params->long_modif)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->short_modif)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (put_number(convert(l, 10, CON_UNSIGNED, params), params));
}



/**
 * put_addrss - puts the address of the character
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes puted
 */
int put_addrss(va_list ap, params_t *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
		return (put_s("(nil)"));

	str = convert(n, 16, CON_UNSIGNED | LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (put_number(str, params));
}
