#include "main.h"
#include <stdarg.h>


/**
  * _printf - creating my own printf function
  * @format: type of argument passed to fuction
  *
  * Return: the character printed
  */

int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	int value = 0;
	va_list args;
	int (*spe)(va_list);

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (format[i])
	{
		if (format[i] != '%')
		{
			value = write(1, &format[i], 1);
			count = count + value;
			i++;
			continue;
		}

		if (format[i] == '%')
		{
			spe = check_specifier(&format[i + 1]);
			if (spe != NULL)
			{
				value = spe(args);
				count = count + value;
				i = i + 2;
				continue;
			}
			if (format[i + 1] == '\0')
			{
				break;
			}
			if (format[i + 1] != '\0')
			{
				value = write(1, &format[i + 1], 1);
				count = count + value;
				i = i + 2;
				continue;
			}

		}
	}
	va_end(args);
	return (count);
}
