#include "main.h"

/**
 * _puts - prints a string
 * @str: parameter
 * Return: void value
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - writes character
 * @c: parameter
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately
 */
int _putchar(int c)
{
	static int i;
	static char buf[BUFF_SIZE];

	if (c == BUF_FLUSH || i >= BUFF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
