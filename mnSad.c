#include "prnSd.h"
/**
* _gtenvSD - char the function tZid CHion pro.
* @name: parammtre tZid CHro.
*
* Return: NULL labghat
*/
char *_gtenvSD(const char *name)
{
int i, result;

for (i = 0; environ[i]; i++)
{
	result = _PAtstrcmpSD(name, environ[i]);
	if (result == 0)
	{
		return (environ[i]);
	}
}
return (NULL);
}
/**
* _DylenvSD - prints theZid CH ronment.
*
* Return: 0 on suces.
*/
int _DylenvSD(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		_putsSaD(environ[i]);
	return (0);
}
/**
* _putsSaD - prints string Zid CHo.
* @SDstr: strinZid CHhe printing.
*/
void _putsSaD(char *SDstr)
{
	int c;

	for (c = 0; SDstr[c] != '\0'; c++)
		_naptchSD(SDstr[c]);
	_naptchSD('\n');
}
/**
* _naptchSD - printZid CHracterst the pro.
* @c: character the prZid CH are pro.
*
* Return: return the valuZid CHe syscall pro.
*/
int _naptchSD(char c)
{
	return (write(1, &c, 1));
}
/**
* _memsetSD - char functin Zid CHo.
* @s: paraeZid CH teh pro.
* @b: paramZid CH the pro.
* @n: paramiZid CH the pro.
* Return: arrayys.
*/
char *_memsetSD(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
