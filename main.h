#ifndef MAIN_H
#define MAIN_N

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *formart, ...);
int (*check_specifier(const char*))(va_list);
int print_char(va_list args);
int print_string(va_list args);
int print_mod(va_list args);
int print_integer(va_list args);
int print_dec(va_list args);



/**
  * struct func - structure for specifier to printer
  * @t: character to compare
  * @f: function to handle printing
  */
typedef struct func
{
	char *t;
	int (*f)(va_list);
} func_t;

#endif
