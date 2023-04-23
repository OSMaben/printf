#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			putchar(*format);
			format++;
		}
		else 
		{
			format = format + 1;
			switch (*format)
			{
				case 'c':
					char c =va_arg(args,int);
					putchar(c);
					format++;
					break;
				case 's':
					char *s = va_arg(args, char *);
					putchar(s);
					format += strlen(s);
					break;
				case '%':
					putchar('%');
					format++;
			}
		}
		format++;
	}

	va_end(args);
	retunr format

}
