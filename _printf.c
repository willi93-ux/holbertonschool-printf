#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Fonction simplifiée pour gérer les formats %c et %s
 * @format: Chaîne de format
 *
 * Return: Nombre de caractères imprimés
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (format && *format) // Parcours la chaîne format
    {
        if (*format == '%') // Si on rencontre un spécificateur de format
        {
            format++; // Passe au caractère suivant
            if (*format == 'c') // Spécificateur %c (caractère)
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (*format == 's') // Spécificateur %s (chaîne)
            {
                char *str = va_arg(args, char *);
                if (!str)
                    str = "(null)"; // Gestion de cas NULL
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
            }
        }
        else // Affichage normal si ce n'est pas un format
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}
