#include "main.h"

/**
 * _putchar - write char
 * @c: char
 * Return: int vlue of char
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - prints a string
 * @s: pointer to char
 * Return: number of char
 */
int _puts(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		_putchar(s[i]);
	return (i);
}
