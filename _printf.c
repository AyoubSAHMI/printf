#include "main.h"
#include <stdio.h>
/**
* _printf - a function that prints everything
* @format: the string to print
* Return: an int number of characters printed
* On error, -1 is returned, and errno is set appropriately.
*/
int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);

int count = 0;

while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
putchar(va_arg(args, int));
count++;
break;
case 's':
{
const char *str = va_arg(args, const char *);

while (*str != '\0')
{
putchar(*str);
count++;
str++;
}
}
break;
case '%':
putchar('%');
count++;
break;
default:
putchar('%');
count++;
break;
}
}
else
{
putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);
}
