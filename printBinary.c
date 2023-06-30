#include "main.h"

/**
  * printBinary - a fun that prints an int value
  * @x: parameter
  * Return: an int value
  */

int printBinary(va_list x)
{
	unsigned int  value = va_arg(x, int);
	int k = 0;
	int arr[64] = {0};
	int index = 0;
	int i = 0;

	if (value == 0)
	{
		_putchar('0');
		k++;
	}
	else if (value > 0)
	{
		while (value)
		{
			int bit = value % 2;

			arr[index] = bit;
			value /= 2;
			k++;
			index++;
		}

		for (i = index - 1; i >= 0; i--)
		{
			_putchar(arr[i] + '0');
		}
	}

	return (k);
}
