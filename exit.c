#include "main.h"

/**
 * handle_exit - handles the exit command
 * Return: void
 */

void handle_exit(void)
{
	char *c = "Exiting program...";

	write(1, c, strlen(c));
	_putchar('\n');
	exit(EXIT_SUCCESS);
}
