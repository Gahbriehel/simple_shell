#include "main.h"

/**
 * _strcspn - get length of substring
 * @reject: string
 * @s: saved string
 *
 * Return: count
 */

size_t _strcspn(const char *s, const char *reject)
{
	size_t count = 0;

	while (*s)
	{
		const char *ptr = reject;

		while (*ptr)
		{
			if (*s == *ptr)
				return (count);
			ptr++;
		}
		s++;
		count++;
	}
	return (count);
}
