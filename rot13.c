#include "main.h"

/**
 * rot13 - encode string to rot13
 * @args: string to encode.
 *
 * Return: encoded string
 */

int rot13(va_list args)
{
	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char b[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i;
	int j;
	char *ptr;

	ptr = va_arg(args, char *);

	if (ptr == NULL)
		return (-1);

	for (i = 0; ptr[i] != '\0'; i++)
	{
		for (j = 0; j <= 52; j++)
		{
			if (ptr[i] == a[i])
			{
				_write(b[i]);
				break;
			}
		}
		if (j == 53)
			_write(ptr[i]);
	}

	return (i);
}
