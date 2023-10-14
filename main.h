#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#define NULL_STRING "(Null)"
#define NUL '\0'
struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert cnvr_t;

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *s);
/**
 * task0
*/
int print_char(va_list l);
int print_string(va_list l);
int print_percent(__attribute__((unused))va_list l);
#endif
