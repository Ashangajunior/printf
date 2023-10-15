#include "main.h"
/**
 * _printf - prints anything
 * @format: string
 * Return: the num of bytes
 */
int _printf(const char *format, ...)
{
	int ch;
	conver_t f_list[] = {
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"c", print_char},
		{"s", print_string},
		{"b", print_binary},
		{"u", print_unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{"S", print_String},
		{"p", print_pointer},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL},
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	ch = _reciever(format, f_list, arg_list);
	va_end(arg_list);
	return (ch);
}
