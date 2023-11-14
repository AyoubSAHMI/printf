#include "main.h"
#include <stdio.h>

int main(void)
{
	int len, len2;

	len = _printf2("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf2("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf2("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf2("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf2("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	len = _printf2("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf2("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf2("Unknown:[%r]\n");
	printf("Unknown:[%r]\n");
	return (0);
}
