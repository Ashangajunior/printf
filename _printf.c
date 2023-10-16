#include "main.h"
/**
 * _printf - prints anything
 * @format: string
 * Return: bytes
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *p, *s;
	para_t para = PARAMS_INIT;

	va_start(ap, format);


	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&para, ap);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		s = p;
		p++;
		while (get_flag(p, &para))
		{
			p++;
		}
		p = get_width(p, &para, ap);
		p = get_precision(p, &para, ap);
		if (get_modifier(p, &para))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(s, p,
				para.l_modifier || para.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, ap, &para);
	}
	_putchar(BUF_FL);
	va_end(ap);
	return (sum);
}
