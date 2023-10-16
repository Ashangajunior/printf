#ifndef _PRINTF_H
#define _PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#define BUF_SIZE 1024
#define BUF_FL -1
#define NULL_S "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
/**
 * struct parameters - parameters
 * @unsign: if unsigned value
 * @plus_flag: if plus_flag
 * @space_flag: if hashtag_flag
 * @hashtag_flag: if _flag specified
 * @zero_flag: if _flag specified
 * @minus_flag: if _flag specified
 * @width: field width
 * @precision: field precision
 * @h_modifier: on if h_modifier
 * @l_modifier: on if l_modifier
 */
typedef struct parameters
{
	unsigned int unsign		: 1;
	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} para_t;

/**
 * struct specifier - Struct token
 * @specifier: format token
 * @f: function
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, para_t *);
} specifier_t;

/* _put.c */
int _puts(char *s);
int _putchar(int c);
/* print_functions.c */
int print_char(va_list ap, para_t *para);
int print_int(va_list ap, para_t *para);
int print_string(va_list ap, para_t *para);
int print_percent(va_list ap, para_t *para);
int print_S(va_list ap, para_t *para);
/* number.c */
char *convert(long int num, int base, int flags, para_t *para);
int print_unsigned(va_list ap, para_t *para);
int print_address(va_list ap, para_t *para);
/* specifier.c */
int (*get_specifier(char *s))(va_list ap, para_t *para);
int get_print_func(char *s, va_list ap, para_t *para);
int get_flag(char *s, para_t *para);
int get_modifier(char *s, para_t *para);
char *get_width(char *s, para_t *para, va_list ap);
/* convert_number.c */
int print_hex(va_list ap, para_t *para);
int print_HEX(va_list ap, para_t *para);
int print_binary(va_list ap, para_t *para);
int print_octal(va_list ap, para_t *para);
/* simple_printers.c */
int print_from_to(char *start, char *stop, char *ex);
int print_rev(va_list ap, para_t *para);
int print_rot13(va_list ap, para_t *para);
/* print_number.c */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, para_t *par);
int print_number_right_shift(char *str, para_t *para);
int print_number_left_shift(char *str, para_t *para);
/* params.c  */
void init_params(para_t *para, va_list ap);
/* string_fields.c  */
char *get_precision(char *p, para_t *para, va_list ap);
/* _prinf.c  */
int _printf(const char *format, ...);
#endif
