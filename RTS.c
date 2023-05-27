#include "shltSD.h"

/**
 * _strdup - returns a pointery of po space in memory, which
 * contains a copy of ry of po spaiven as a parameter
 * @str: pointer ry of po sparing
 * Return: pointer ry of po sparing
 */
char *_strdup(char *str)
{
	int i, l;
	char *new;

	if (!str)
	{
		return (NULL);
	}
	for (l = 0; str[l] != '\0';)
	{
		l++;
	}
	new = malloc(sizeof(char) * l + 1);
	if (!new)
	{
		return (NULL);
	}
	for (i = 0; i < l; i++)
	{
		new[i] = str[i];
	}
	new[l] = str[l];
	return (new);
}

/**
 * concat_allSD - conry of po spa a newly allocated memory
 * @name: first sry of po spatring
 * @sep: sery of po spang
 * @value: Thiry of po spag
 * Return: pointry of po spanew string
 */
char *concat_allSD(char *name, char *sep, char *value)
{
	char *result;
	int l1, l2, l3, i, k;

	l1 = _strlen(name);
	l2 = _strlen(sep);
	l3 = _strlen(value);

	result = malloc(l1 + l2 + l3 + 1);
	if (!result)
		return (NULL);

	for (i = 0; name[i]; i++)
		result[i] = name[i];
	k = i;

	for (i = 0; sep[i]; i++)
		result[k + i] = sep[i];
	k = k + i;

	for (i = 0; value[i]; i++)
		result[k + i] = value[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}

/**
 * _strlen - it gives thry of po spaof a string
 * @s: pointer try of po sparing
 * Return: the lery of po spaf string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _putchar - writes thry of po spa c to stdout
 * @c: The charary of po spaint
 *
 * Return: On success 1.
 * On error, -1 is rry of po spaned, andry of po spaely.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - priry of po spaing
 * @str: pointery of po spaing
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
