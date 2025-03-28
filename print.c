#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Function to handle format specifiers
 * @format: The format string to print
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (format && *format) // Parcourt la chaîne format
    {
        if (*format == '%') // Si on rencontre un spécificateur de format
        {
            format++; // Passe à l'élément suivant
            if (*format == 'c') // Si c'est un spécificateur de caractère
            {
                char c = va_arg(args, int); // Récupère le caractère
                write(1, &c, 1); // Affiche le caractère
                count++;
            }
            else if (*format == 's') // Si c'est un spécificateur de chaîne
            {
                const char *str = va_arg(args, const char*); // Récupère la chaîne
                while (*str) // Affiche chaque caractère de la chaîne
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
            }
        }
        else // Si ce n'est pas un spécificateur, afficher le caractère normal
        {
            write(1, format, 1);
            count++;
        }
        format++; // Passe au caractère suivant de format
    }

    va_end(args);

    return count; // Retourne le nombre de caractères imprimés
}
