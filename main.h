#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...);
int _putchar(char c);
int printNumberWithPutchar(int number);
int Sprintf(char *str);
int str_length(char *s);
int binprint(unsigned int num);
#endif
