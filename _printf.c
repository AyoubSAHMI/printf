#include "main.h"
/**
 *_printf - copy content to output
 *@format: first string.
 *Return: length of printed content
 */
int _printf(const char *format, ...)
{
int i, length;
char *str;
va_list l;
i = length = 0;
va_start(l, format);
if (format == NULL)
return (-1);
while (format[i] != '\0')
{
if (format[i] == '%')
{
if (format[i + 1] == '\0')
return (-1);
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
if (str == NULL)
str = "";
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
