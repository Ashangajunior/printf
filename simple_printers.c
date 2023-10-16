#include "main.h"
/**
 * print_from_to - prints char
 * @start: address
 * @stop: address
 * @ex: address
 * Return: sum value
 */
int print_from_to(char *start, char *stop, char *ex)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != ex)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}
/**
 * print_rev - the rev of string
 * @ap: string
 * @para: parameter
 * Return: sum value
 */
int print_rev(va_list ap, para_t *para)
{
	int len, s = 0;
	char *str = va_arg(ap, char *);
	(void)para;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			s += _putchar(*str);
	}
	return (s);
}
/**
 * print_rot13 - prints rot13
 * @ap: string
 * @para: parameter
 * Return: bytes num
 */
int print_rot13(va_list ap, para_t *para)
{
	int i = 0, index = 0;
	int c = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *s = va_arg(ap, char *);
	(void)para;

	while (s[i])
	{
		if ((s[i] >= 'A' && s[i] <= 'Z')
		    || (s[i] >= 'a' && s[i] <= 'z'))
		{
			index = s[i] - 65;
			c += _putchar(arr[index]);
		}
		else
			c += _putchar(s[i]);
		i++;
	}
	return (c);
}
