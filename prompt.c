#include "main.h"

/**
 * handle_user_input - function to handle inputs and commands
 * input: pointer to string
 * bufferSize: size of buffer
 * numChars: line from stream
 * Return: void
 */

void handle_user_input(void)
{
	char *input = NULL;
	size_t bufferSize = 0;
	ssize_t numChars;

	my_printf("$ ");

	numChars = my_getline(&input, &bufferSize, stdin);

	if (numChars == -1)
	{
		if (feof(stdin))
		{
			my_printf("\n");
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}

	input[strcspn(input, "\n")] = '\0';

	if (strcmp(input, "exit") == 0)
	{
		free(input);
		handle_exit();
	}
	else
	{
		execute(input);
	}

	free(input);
}
