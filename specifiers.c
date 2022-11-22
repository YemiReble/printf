#include "main.h"

/**
  * check_specifier - this is a function that holds the specifier of _printf\
  * as per ALX specification.
  * @format: the secifier character (char *)
  *
  * Return: pointer to a fucntion
  */

int (*check_specifier(const char *format))(va_list)
{
	int i;

	func_t array[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_mod},
		{"i", print_integer},
		{"d", print_dec},
		{NULL, NULL}};

	for (i = 0; array[i].t != NULL; i++)
	{
		if (*(array[i].t) == *format)
		{
			return (array[i].f);
		}
	}
	return (NULL);
}
