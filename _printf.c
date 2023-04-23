#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;

	while (*format != '\0')
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
			format++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						char c = va_arg(args, int);
						_putchar(c);
						count++;
						break;
					}

				case 's':
					{
						char *s = va_arg(args, char *);
						while (*s != '\0')
						{
							_putchar(*s);
							count++;
							s++;
						}
						break;
					}

				case '%':
					{
						_putchar('%');
						count++;
						break;
					}

				default:
					{
						_putchar('%');
						count++;
						_putchar(*format);
						count++;
						break;
					}

			}
			format++;
		}
	}

	va_end(args);
	return count;
}

