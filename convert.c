#include "main.h"
/**
 * convert - converter function
 * @num: number argument
 * @base: base
 * @flags: argument flags
 * @para: paramater struct
 * Return: string
 */
char *convert(long int num, int base, int flags, para_t *para)
{
	static char *array;
	static char buff[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)para;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buff[49];
	*ptr = '\0';
	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}
/**
 * print_unsigned - prints unsigned integer
 * @ap: pointer
 * @para: parameters struct
 * Return: bytes printed
 */
int print_unsigned(va_list ap, para_t *para)
{
	unsigned long l;

	if (para->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (para->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	para->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, para), para));
}
/**
 * print_address - prints address
 * @ap: pointer
 * @para: parameters struct
 * Return: bytes printed
 */
int print_address(va_list ap, para_t *para)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *s;

	if (!n)
		return (_puts("(nil)"));
	s = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, para);
	*--s = 'x';
	*--s = '0';
	return (print_number(s, para));
}
