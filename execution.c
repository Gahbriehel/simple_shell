#include "main.h"

/**
 * execute - function to execute command
 * @input: pointer to string
 * Return: void
 */
extern char **environ;

void execute(const char *input)
{
	pid_t pid;

	if (strcmp(input, "") != 0)
	{
		char **args = malloc(2 * sizeof(char *));

		if (!args)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		args[0] = strdup(input);
		if (!args[0])
		{
			perror("strdup");
			free(args);
			exit(EXIT_FAILURE);
		}
		args[1] = NULL;
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			free(args[0]);
			free(args);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			execve(input, args, environ);
			perror("execve");
			free(args[0]);
			free(args);
			exit(EXIT_FAILURE);
		}
		wait(NULL);
		free(args[0]);
		free(args);
	}
}
