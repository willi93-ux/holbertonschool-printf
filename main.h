#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Déclaration des fonctions */
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_number(va_list args);

#endif /* PRINTF_H */
