#include "main.h"
/**
 * get_specifier - finds the format function
 * @s: parameter
 * Return: the num of bytes
 */
int (*get_specifier(char *s))(va_list ap, para_t *para)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{"S", print_S},
		{"p", print_address},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}
/**
 * get_print_func - finds the format func
 * @s: the format string
 * @ap: pointer
 * @para: parameters struct
 * Return: int value
 */
int get_print_func(char *s, va_list ap, para_t *para)
{
	int (*f)(va_list, para_t *) = get_specifier(s);

	if (f)
		return (f(ap, para));
	return (0);
}
/**
 * get_flag - finds the flag
 * @s: the format string
 * @para: the parameters struct
 * Return: flag validation
 */
int get_flag(char *s, para_t *para)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = para->plus_flag = 1;
			break;
		case ' ':
			i = para->space_flag = 1;
			break;
		case '#':
			i = para->hashtag_flag = 1;
			break;
		case '-':
			i = para->minus_flag = 1;
			break;
		case '0':
			i = para->zero_flag = 1;
			break;
	}
	return (i);
}
/**
 * get_modifier - finds the modifier func
 * @s: the format string
 * @para: the parameters struct
 * Return: i value
 */
int get_modifier(char *s, para_t *para)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = para->h_modifier = 1;
		break;
	case 'l':
		i = para->l_modifier = 1;
		break;
	}
	return (i);
}

/**
 * get_width - gets the width
 * @s: the format string
 * @para: parameters struct
 * @ap:  argument pointer
 * Return: pointer
 */
char *get_width(char *s, para_t *para, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	para->width = d;
	return (s);
}
