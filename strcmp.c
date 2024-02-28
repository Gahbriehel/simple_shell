#include "main.h"

/**
 * custom_strcmp - compare string values
 * @s1: input value
 * @s2: input value
 *
 * Return: s1[i] - s2[i]
 */

int custom_strcmp(char *s1, char *s2)
{
	int i;

	if (s1 == NULL && s2 == NULL)
		return (0);

	if (s1 == NULL)
		return (-1);

	if (s2 == NULL)
		return (1);

	i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}

	return (s1[i] - s2[i]);
}
