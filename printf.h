#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>

/**
 * _printf - Fonction simplifiée pour gérer les formats %c et %s
 * @format: Chaîne de format
 *
 * Return: Nombre de caractères imprimés
 */
int _printf(const char *format, ...);

#endif /* PRINTF_H */
