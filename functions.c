#include "main.h"
/**
 * print_char - prints character
 * @ap: pointer
 * @para: parameters struct
 * Return: char num
 */
int print_char(va_list ap, para_t *para)
{
	char pad_ch = ' ';
	unsigned int pad = 1, s = 0, ch = va_arg(ap, int);

	if (para->minus_flag)
		s += _putchar(ch);
	while (pad++ < para->width)
		s += _putchar(pad_ch);
	if (!para->minus_flag)
		s += _putchar(ch);
	return (s);
}
/**
 * print_int - prints integer
 * @ap: pointer
 * @para: parameters struct
 * Return: number chars
 */
int print_int(va_list ap, para_t *para)
{
	long l;

	if (para->l_modifier)
		l = va_arg(ap, long);
	else if (para->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, para), para));
}
/**
 * print_string - prints string
 * @ap: argument pointer
 * @para: parameters struct
 * Return: number chars printed
 */
int print_string(va_list ap, para_t *para)
{
	char *str = va_arg(ap, char *), pad_ch = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)para;
	switch ((int)(!str))
		case 1:
			str = NULL_S;
	j = pad = _strlen(str);
	if (para->precision < pad)
		j = pad = para->precision;
	if (para->minus_flag)
	{
		if (para->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < para->width)
		sum += _putchar(pad_ch);
	if (!para->minus_flag)
	{
		if (para->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}
/**
 * print_percent - prints string
 * @ap: argument pointer
 * @para: parameters struct
 * Return: % mod
 */
int print_percent(va_list ap, para_t *para)
{
	(void)ap;

	(void)para;
	return (_putchar('%'));
}
/**
 * print_S - prints modified string
 * @ap: argument pointer
 * @para: parameters struct
 * Return: number chars printed
 */
int print_S(va_list ap, para_t *para)
{
	char *s = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int)(!s))
		return (_puts(NULL_S));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*s, 16, 0, para);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*s);
		}
	}
	return (sum);
}
