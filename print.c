#include "main.h"

/**
 * my_printf - function to print
 * @format: pointer to chars
 *
 * Return: void
 */

void my_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	vprintf(format, args);

	va_end(args);
}
