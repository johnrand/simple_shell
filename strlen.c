#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: pointer to string
 *
 * @len varaible.the function returns @len
 *
 * Return: length of string
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
