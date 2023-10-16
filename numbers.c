#include "main.h"
/**
 * _isdigit - checks if digit
 * @c: check char
 * Return: int value
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/**
 * _strlen - the length
 * @s: the checker
 * Return: int length of string
 */
int _strlen(char *s)
{
	int j = 0;

	while (*s++)
		j++;
	return (j);
}
/**
 * print_number - prints numbers
 * @str: the base number as a string
 * @para: parameter struct
 * Return: char value
 */
int print_number(char *str, para_t *para)
{
	unsigned int n = _strlen(str);
	int neg = (!para->unsign && *str == '-');

	if (!para->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		n--;
	}
	if (para->precision != UINT_MAX)
		while (n++ < para->precision)
			*--str = '0';
	if (neg)
		*--str = '-';
	if (!para->minus_flag)
		return (print_number_right_shift(str, para));
	else
		return (print_number_left_shift(str, para));
}
/**
 * print_number_right_shift - prints num in rihgt
 * @str: the base number as a string
 * @para: parameter struct
 * Return: chars value
 */
int print_number_right_shift(char *str, para_t *para)
{
	unsigned int n = 0, neg, neg2, b = _strlen(str);
	char pad_ch = ' ';

	if (para->zero_flag && !para->minus_flag)
		pad_ch = '0';
	neg = neg2 = (!para->unsign && *str == '-');
	if (neg && b < para->width && pad_ch == '0' && !para->minus_flag)
		str++;
	else
		neg = 0;
	if ((para->plus_flag && !neg2) ||
			(!para->plus_flag && para->space_flag && !neg2))
		b++;
	if (neg && pad_ch == '0')
		n += _putchar('-');
	if (para->plus_flag && !neg2 && pad_ch == '0' && !para->unsign)
		n += _putchar('+');
	else if (!para->plus_flag && para->space_flag && !neg2 &&
		!para->unsign && para->zero_flag)
		n += _putchar(' ');
	while (b++ < para->width)
		n += _putchar(pad_ch);
	if (neg && pad_ch == ' ')
		n += _putchar('-');
	if (para->plus_flag && !neg2 && pad_ch == ' ' && !para->unsign)
		n += _putchar('+');
	else if (!para->plus_flag && para->space_flag && !neg2 &&
		!para->unsign && !para->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}
/**
 * print_number_left_shift - prints numbers in left
 * @str: the base number as a string
 * @para: parameter struct
 * Return: chars printed
 */
int print_number_left_shift(char *str, para_t *para)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_ch = ' ';

	if (para->zero_flag && !para->minus_flag)
		pad_ch = '0';
	neg = neg2 = (!para->unsign && *str == '-');
	if (neg && i < para->width && pad_ch == '0' && !para->minus_flag)
		str++;
	else
		neg = 0;
	if (para->plus_flag && !neg2 && !para->unsign)
		n += _putchar('+'), i++;
	else if (para->space_flag && !neg2 && !para->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < para->width)
		n += _putchar(pad_ch);
	return (n);
}
