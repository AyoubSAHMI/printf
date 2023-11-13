#include "main.h"
/**
 * _printf - a function that prints everything
 * @format: the string to print
 * Return: an int number of characters printed
 * On error, -1 is returned, and errno is set appropriately.
 */
#include "main.h"

int _printf(const char *format, ...)
{
	int char_print, str_length;
	char c;
	char *str;
	va_list l;

	str_length = 0;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(l, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			if (*format == '%')
			{
				write(1, format, 1);
				char_print++;
			}
			else if (*format == 'c')
			{
				c = va_arg(l, int);
				write(1, &c, 1);
				char_print++;
			}
			else if (*format == 's')
			{
				str = va_arg(l, char*);
				while (str[str_length] != '\0')
				{
					str_length++;
					write(1, str, str_length);
					char_print += str_length;
				}
			}
		}
		format++;
	}
	va_end(l);
	return (char_print);
}
