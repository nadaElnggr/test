#include "main.h"

/**
  * printchar - a fun that prints char
  * @x: parameter
  * Return: an int value
  */
int printchar(va_list x)
{
	char ch = va_arg(x, int);

	_putchar(ch);

	return (1);
}
