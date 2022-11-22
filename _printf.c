#include "main.h"
/**
 * _printf - function to print anything
 * @format: types of argument passed to the function
 *
 *  Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int check = 0, i;
	va_list args;
	int (*func)(va_list);

	va_start(args, format);

	if (format == NULL)
		return (-1);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (!(format[i]))
				return (-1);

			func = specifier(format[i]);

			if (func == NULL)
			{
				_write('%');
				_write(format[i]);
				check += 2;
			}
			else
				check += func(args);
		}
		else
		{
			_write(format[i]);
			check++;
		}
	}
	va_end(args);
	return (check);
}
