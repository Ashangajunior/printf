#include "main.h"

/**
 * get_precision - gets the precision
<<<<<<< HEAD
 * @p: the format strings
 * @params: the parameters struct
=======
 * @p: the format string
 * @para: the parameters struct
>>>>>>> ad3a01405bd88f77715168d7bbec7c0b90f37da0
 * @ap: pointer
 * Return: p value
 */
char *get_precision(char *p, para_t *para, va_list ap)
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
	para->precision = i;
	return (p);
}
