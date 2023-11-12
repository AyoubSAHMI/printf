#include "main.h"
/**
 *_putchar - a function that prints a character
 *@c: the char to print
 *Return: an int
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
