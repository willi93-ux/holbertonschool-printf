#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - Affiche un caractère
 * @args: Liste d'arguments
 *
 * Return: Nombre de caractères imprimés
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string - Affiche une chaîne de caractères
 * @args: Liste d'arguments
 *
 * Return: Nombre de caractères imprimés
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}

/**
 * print_number - Affiche un entier
 * @args: Liste d'arguments
 *
 * Return: Nombre de caractères imprimés
 */
int print_number(va_list args)
{
	int num = va_arg(args, int);
	char buffer[12];
	int i = 0, count = 0;
	int is_negative = (num < 0);

	if (is_negative)
	{
		write(1, "-", 1);
		num = -num;
		count++;
	}

	do {
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	while (i--)
		count += write(1, &buffer[i], 1);

	return (count);
}

/**
 * _printf - Fonction pour gérer %c, %s, %d et %i
 * @format: Chaîne de format
 *
 * Return: Nombre de caractères imprimés
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				count += print_char(args);
			else if (*format == 's')
				count += print_string(args);
			else if (*format == 'd' || *format == 'i')
				count += print_number(args);
			else
				count += write(1, format - 1, 2); /* Gère les % inconnus */
		}
		else
			count += write(1, format, 1);

		format++;
	}

	va_end(args);
	return (count);
}
