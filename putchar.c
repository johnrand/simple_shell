#include "main.h"

/**
 * _putchar - prints characters on output
 * @c: character to be printed
 *
 * Return: character
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
