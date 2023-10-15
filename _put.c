#include "main.h"
/**
 * _puts - prints a string
 * @s: pointer to char
 * Return: number of char
 */
int _puts(char *s)
{
	char *i = s;


	while (*s)
		_putchar(*s++);
	return (s - i);
}
/**
 * _putchar - write char
 * @c: char
 * Return: int vlue of char
 */
int _putchar(int c)
{
	static int i;
	static char b[BUF_SIZE];

	if (c == BUF_FL || i >= BUF_SIZE)
	{
		write(1, b, i);
		i = 0;
	}
	if (c != BUF_FL)
		b[i++] = c;
	return (1);
}
