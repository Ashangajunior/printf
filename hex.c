#include "main.h"
/**
 * print_hex - prints unsigned hex number
 * @ap: pointer
 * @para: parameters struct
 * Return: bytes printed
 */
int print_hex(va_list ap, para_t *para)
{
	unsigned long l;
	int c = 0;
	char *s;

	if (para->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (para->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	s = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, para);
	if (para->hashtag_flag && l)
	{
		*--s = 'x';
		*--s = '0';
	}
	para->unsign = 1;
	return (c += print_number(s, para));
}
/**
 * print_HEX - prints unsigned hex numbers in capital
 * @ap: argument pointer
 * @para: parameters struct
 * Return: bytes printed
 */
int print_HEX(va_list ap, para_t *para)
{
	unsigned long l;
	int c = 0;
	char *s;

	if (para->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (para->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	s = convert(l, 16, CONVERT_UNSIGNED, para);
	if (para->hashtag_flag && l)
	{
		*--s = 'X';
		*--s = '0';
	}
	para->unsign = 1;
	return (c += print_number(s, para));
}
/**
 * print_binary - prints unsigned binary
 * @ap: argument pointer
 * @para: parameters struct
 * Return: bytes printed
 */
int print_binary(va_list ap, para_t *para)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *s = convert(n, 2, CONVERT_UNSIGNED, para);
	int c = 0;

	if (para->hashtag_flag && n)
		*--s = '0';
	para->unsign = 1;
	return (c += print_number(s, para));
}
/**
 * print_octal - prints unsigned octal number
 * @ap: pointer
 * @para: parameter
 * Return: bytes printed
 */
int print_octal(va_list ap, para_t *para)
{
	unsigned long l;
	char *s;
	int c = 0;

	if (para->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (para->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	s = convert(l, 8, CONVERT_UNSIGNED, para);
	if (para->hashtag_flag && l)
		*--s = '0';
	para->unsign = 1;
	return (c += print_number(s, para));
}
