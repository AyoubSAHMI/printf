#include "main.h"
/**
 * _printf - a function that prints everything
 * @format: the string to print
 * Return: an int number of characters printed
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printf(const char *format, ...)
{
	int i;
	char *str;
	int length;
	va_list l;

	i = 0;
	length = 0;

	va_start(l, format);

	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				_putchar(va_arg(l, int));
				i++;
			}
			if (format[i + 1] == '%')
			{
				_putchar('%');
				i++;
			}
			if (format[i + 1] == 's')
			{
				str = va_arg(l, char*);
				write(1, str, strlen(str));
				length += (strlen(str) - 1);
				i++;
			}
		}
		else
		_putchar(format[i]);
		length++;
		i++;
	}
	va_end(l);
	return (length);
}
