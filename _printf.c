#include "main.h"
/**
 *_printf - Print formatted output
 *@format: first string.
 *Return: length of printed content
 */
int _printf(const char *format, ...)
{
	int length, str_len;
	char *str, c;
	va_list l;

	length = 0;
	str_len = 0;
	va_start(l, format);

	if (format == NULL)
	{
		return (-1);
	}
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			length++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			else if (*format == 'c')
			{
				c = va_arg(l, int);
				write(1, &c, 1);
				length++;
			}
			else if (*format == 's')
			{
				str = va_arg(l, char*);
				while (str[str_len] != '\0')
				{
					str_len++;
				}
				write(1, str, str_len);
				length += str_len;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				length++;
			}
		}
		format++;
	}
	va_end(l);
	return (length);
}
