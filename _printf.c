#include "main.h"
#include <limits.h>
/**
*_printf - Print formatted output
*@format: first string.
*Return: length of printed content
*/
int _printf(const char *format, ...)
{
	int i, length, decimal, count_number, string_length;
	char *str;
	char *error;
	va_list l;
	i = length = 0;
	va_start(l, format);
	if (format == NULL)
	{
		return (-1);
	}
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				return (-1);
			}
			else if (format[i + 1] == 'c')
			{
				_putchar(va_arg(l, int));
				i++;
			}
			else if (format[i + 1] == '%')
			{
				_putchar('%');
				i++;
			}
			else if (format[i + 1] == 's')
			{
				str = va_arg(l, char*);
				string_length = Sprintf(str);
				length += string_length;
				i++;
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				decimal = va_arg(l, int);
				if(decimal >= INT_MIN && decimal <= INT_MAX)
				  {
				count_number = printNumberWithPutchar(decimal);
				length += (count_number - 1);
				  }
				else
				  return (-1);
				i++;
			}
			else
			{
				error = "unIdentified formatter\n";
				write(1, error, str_length(error));
				return (-1);
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
