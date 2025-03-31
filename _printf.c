#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Fonction simplifiée pour gérer les formats %c, %s, %d et %i
 * @format: Chaîne de format contenant les spécificateurs
 *
 * Return: Nombre de caractères imprimés
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (format && *format) /* Parcours la chaîne format */
	{
		if (*format == '%') /* Si on rencontre un spécificateur */
		{
			format++; /* Passe au caractère suivant */

			if (*format == 'c') /* Spécificateur %c (caractère) */
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				count++;
			}
			else if (*format == 's') /* Spécificateur %s (chaîne) */
			{
				char *str = va_arg(args, char *);

				if (!str)
					str = "(null)"; /* Gestion de cas NULL */
				while (*str)
				{
					write(1, str, 1);
					str++;
					count++;
				}
			}
			else if (*format == 'd' || *format == 'i') /* Spécificateur %d et %i */
			{
				int num = va_arg(args, int);
				char buffer[12];
				int len = 0, temp = num, div = 1, i;

				if (num < 0)
				{
					write(1, "-", 1);
					count++;
					num = -num;
				}
				while (temp / 10)
				{
					div *= 10;
					temp /= 10;
				}
				while (div)
				{
					buffer[len++] = (num / div) + '0';
					num %= div;
					div /= 10;
				}
				for (i = 0; i < len; i++)
				{
					write(1, &buffer[i], 1);
					count++;
				}
			}
		}
		else /* Affichage normal si ce n'est pas un format */
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}
