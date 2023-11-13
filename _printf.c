#include "main.h"
/**
 *_printf - Print formatted output
 *@format: first string.
 *Return: length of printed content
 */
int _printf(const char *format, ...)
{
int i, length;
int decimal, count_number;
char *str;
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
		if (format[i + 1] == 'c')
		{
			if (va_arg(l, int))
			{
			_putchar(va_arg(l, int));
			i++;
			}
			else
			{
				_putchar("");
			}
		}
		if (format[i + 1] == '%')
		{
			_putchar('%');
			i++;
		}
		if (format[i + 1] == 's')
		{
			str = va_arg(l, char*);
			if (str == NULL)
			{
				write(1, "(null)", strlen("(null)"));
				length += strlen("(null)");
			}
			else if (str == '\0')
			{
				_putchar("");
			}
			else
			{
			write(1, str, strlen(str));
			length += (strlen(str) - 1);
			i++;
			}
if (format[i + 1] == 'd' || format[i + 1] == 'i')
{
decimal = va_arg(l, int);
count_number = printNumberWithPutchar(decimal);
length += count_number;
i++;
}
else
_putchar(format[i]);
length++;
i++;
}
va_end(l);
return (length);
}
