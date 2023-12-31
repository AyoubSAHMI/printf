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
/**
 *_strlen - a function that returns a int
 *@s: the string we'll count its characters
 *Return: number of characters
 */
int str_length(char *s)
{
	int i;
	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
   Adding new functions*/
/**
 * Sprintf - print caracter string
 * @str: pointer to string
 * Return: length of string
 */
int Sprintf(char *str)
{
	int charCount;
	charCount = 0;
	if (str == NULL)
	{
		str = "";
		write(1, str, 1);
		return (-1);
	}
	write(1, str,str_length(str));
	charCount += (str_length(str) - 1);
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
	/*Handle the case when the number is zero separately*/
	if (number == 0)
	{
		_putchar('0');
		return(1);
	}
	/**
	 *If the number is negative,
	*/
	/* print the minus sign and make it positive*/
	if (number < 0)
	{
		_putchar('-');
		number = -number;
	}
	/**
	   Determine the number of digits*/
	temp = number;
	digitCount = 0;
	while (temp != 0)
	{
		temp /= 10;
		++digitCount;
	}
	final_count = digitCount;
	/**
	   Extract each digit and print it*/
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
/**
 *binprint - a function that print a number in binary
 *@num: the number we'll convert in binary
 *Return: number of printed digits
 */
int binprint(unsigned int num)
{
	int i = 0;
	int j;
	int ptr[64];
	if (num == 0)
	{
		_putchar(0 + '0');
		return(1);
	}
	
		while (num >= 1)
		{

			ptr[i] = (num % 2);
			num = (num / 2);
			i++;
		}

		for (j = i - 1; j >= 0 ;j--)
		{
			_putchar(ptr[j] + '0');
		}
	
	return (i);
}
