#include "main.h"
#include <unistd.h>

/**
 * printstr - a fun that prints a string
 * @x: parameter
 * Return: an int value
*/

int printstr(va_list x)
{
	char *str = va_arg(x, char *);
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
