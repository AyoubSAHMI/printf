#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
/*Adding new functions*/
/**
 * Sprintf - print caracter string
 * @str: pointer to string
 * Return: length of string
 */
int Sprintf(char *str)
{
  int charCount, i;
   charCount = 0;
   if (str == NULL)
      {
        return (-1);
      }
    else
     write(1, str, strlen(str));                             
    charCount += (strlen(str) - 1);
    return (charCount);
}
/**
*printNumberWithPutchar - A function that prints
*the digits of a number
*@number: the number we will count digits of
*Return: number of characters printed
*/

int printNumberWithPutchar(int number)
{
int i, divisor;
int temp, digitCount;
int digit, final_count;
/* Handle the case when the number is zero separately*/
if (number == 0)
{
_putchar('0');
}
/*If the number is negative,*/
/* print the minus sign and make it positive*/
if (number < 0)
{
_putchar('-');
number = -number;
}
/* Determine the number of digits*/
temp = number;
digitCount = 0;
while (temp != 0)
{
temp /= 10;
++digitCount;
}
final_count = digitCount;
/* Extract each digit and print it*/
while (digitCount > 0)
{
divisor = 1;
for (i = 1; i < digitCount; ++i)
{
divisor *= 10;
}
digit = number / divisor;
_putchar('0' + digit);
number %= divisor;
--digitCount;
}
return (final_count);
}
