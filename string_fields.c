#include "main.h"

/**
 * get_precision - gets the precision
 * @p: the format string
 * @para: the parameters struct
 * @ap: pointer
 * Return: p value
 */
char *get_precision(char *p, para_t *para, va_list ap)
{
	int d = 0;


	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	para->precision = d;
	return (p);
}
