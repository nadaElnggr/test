#include "main.h"

/**
  * select_format - a fun that specify which fun to perform
  * @ptr: parameter
  * @idx: parameter
  * Return: an int value
  */
int (*select_format(const char *ptr, int *idx))()
{
	fmt selection[] = {
		{"c", printchar},
		{"s", printstr},
		{"d", printdeci},
		{"i", printint},
		{"b", printBinary}
	};

	int len = 5;
	int tmp_idx = *idx;
	int i;

	while (len--)
	{
		tmp_idx = *idx;
		i = 0;

		while (ptr[tmp_idx] && selection[len].s[i]
				&& ptr[tmp_idx] == selection[len].s[i])
			++tmp_idx, ++i;

		if (!selection[len].s[i])
			break;
	}

	if (len < 0)
		return (NULL);

	*idx = tmp_idx;

	return (selection[len].select_format);
}

/**
  * printpercentage - a fun that checks mulitple percentage
  * @ptr: parameter
  * @idx: parameter
  * @c: parameter
  * Return: an int value
  */

int printpercentage(const char *ptr, int *idx, int *c)
{
	int s = 1;

	while (ptr[*idx + 1] && ptr[*idx + 1] == '%')
	{
		s = !s;

		if (!s)
		{
			_putchar(ptr[*idx]);
			(*c)++;
		}

		(*idx)++;
	}

	(*idx)++;

	return (s);
}

/**
  * _printf - a fun that prints buffer stream to output stream
  * @format: parameter
  * @...: parameter
  * Return: an int value
  */
int _printf(const char *format, ...)
{
	int idx = 0,
		c = 0;

	int (*printfmt)();
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[idx])
	{
		if (format[idx] == '%')
		{
			if (!printpercentage(format, &idx, &c))
				continue;

			printfmt = select_format(format, &idx);

			if (!printfmt)
			{
				_putchar('%');
				c++;
				continue;
			}

			c += printfmt(args);
		}
		else
		{
			_putchar(format[idx++]);
			++c;
		}
	}

	va_end(args);

	return (c);
}
