#include "main.h"
/**
 * print_from_to - prints char
 * @start: address
 * @stop: address
 * @except: address
 * Return: sum value
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}
