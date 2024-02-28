#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>


void my_printf(const char *format, ...);
void handle_exit(void);
void execute(const char *input);
void handle_user_input(void);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);


#endif
