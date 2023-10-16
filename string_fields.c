#include "main.h"

/**
 * get_precision - gets the precision
 * @p: the format strings
 * @params: the parameters struct
 * @ap: pointer
 * Return: p value
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	int i = 0;


	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		i = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			i = i * 10 + (*p++ - '0');
	}
	params->precision = i;
	return (p);
}
