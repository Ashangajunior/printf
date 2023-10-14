#include "main.h"
/**
 * print_char - Prints character
 * @l: the arg
 * Return: charachters
 */
int print_char(va_list l)
{
	_putchar(va_arg(l, int));
	return (1);
}

/**
 * print_string - Prints a string
 * @l: arg
 * Return: i value
 */
int print_string(va_list l)
{
	int i;
	char *s;

	s = va_arg(list, char *);
	if (s == NULL)
		s = "(Null)";
	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
	return (i);
}

/**
 * print_percent - Prints %
 * @l: arg
 * Return: success
 */
int print_percent(__attribute__((unused))va_list l)
{
	_putchar('%');
	return (1);
}
