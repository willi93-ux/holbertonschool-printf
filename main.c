#include <stdio.h>
#include "printf.h"

int _printf(const char *format, ...);

int main(void)
{
    int len;

    len = _printf("Test simple\n");
    _printf("Caractère : %c\n", 'A');
    _printf("Chaîne : %s\n", "Holberton");

    printf("Nombre de caractères imprimés : %d\n", len);
    return (0);
}
