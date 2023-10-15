#include "main.h"
/**
 * _printf - prints anything
 * @format: string
 * Return: the num of bytes
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list i;
	char *p, *s;
	params_t params = PARAMS_INIT;

	va_start(i, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, i);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		s = p;
		p++;
		while (get_flag(p, &params))
		{
			p++;
		}
		p = get_width(p, &params, i);
		p = get_precision(p, &params, i);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(s, p,
				params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, i, &params);
	}
	_putchar(BUF_FL);
	va_end(i);
	return (sum);
}
