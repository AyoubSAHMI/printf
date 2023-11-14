#include "main.h"
/**
 *_printf - Print formatted output
 *@format: first string.
 *Return: length of printed content
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0; // to count the number of characters printed
    char c;

    while (*format) {
        if (*format == '%' && *(format + 1) != '\0') {
            format++; // move past '%'
            switch (*format) {
                case 'c':
                    c = (char) va_arg(args, int);
                    _putchar(c);
                    count++;
                    break;
                case 's':
                    {
                        const char *str = va_arg(args, const char *);
                        while (*str) {
                           _putchar(*str);
                            str++;
                            count++;
                        }
                    }
                    break;
                case '%':
                    _putchar('%');
                    count++;
                    break;
                default:
                    _putchar('%');
                    _putchar(*format);
                    count += 2;
                    break;
            }
        } else {
            _putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}
