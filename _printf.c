#include "main.h"
int  my_printf(const char *format, ...)
{
	unsigned h = 0, r_value = 0;
	va_list args;
	va_start(args, format);

	for ( ; format[h] != '\0' ; h++)
	{
		if (format[h] != '%')
		{
			_putchar(format[h]);
		}
		else if (format[h+1] == 'c')
		{
			_putchar(va_arg(args, int));
			h++;
		}
		else if (format[h+1] == 's')
		{
			int r_val = put_s(va_arg(args, char *));
			h++;
			r_value += (r_val - 1);
		}
		else if (format[h+1] == '%')
		{
			_putchar('%');
			h++;
		}
		r_value += 1;
	}
	return (r_value);
}




int put_s(char *string)
{
	int idx = 0, r_val = 0;

	if (string)
	{
		while (string[idx] != '\0')
		{
			_putchar(string[idx]);
			r_val += 1;
			idx++;
		}
	}
	return (r_val);
}



int _putchar(char c)
{
	    return (write(1, &c, 1));
}


