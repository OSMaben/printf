#include "main.h"

/**
 * _putchar - writes a character to the output buffer
 * 
 * @c: the character to be written
 * 
 * Return: the number of characters
 */

int _putchar(char c)
{
    return (write(1, &c, 1));
}
