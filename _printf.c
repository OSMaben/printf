#include "main.h"
/**
 * _printf - function similar toputf of
 * standard library functions
 * @format:the formated string after modification
 *
 * Return: number of bytesputed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list args;
	char *p, *start;
	params_t params = PARAMETERS;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, args);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (hold_flag(p, &params))
		{
			p++;
		}
		p = hold_width(p, &params, args);
		p = hold_precision(p, &params, args);
		if (hold_modifier(p, &params))
			p++;
		if (!hold_specifier(p))
			sum += put_from_to(start, p,
				params.long_modif || params.short_modif ? p - 1 : 0);
		else
			sum += hold_put_func(p, args, &params);
	}
	_putchar(BUFFER_SH);
	va_end(args);
	return (sum);
}
