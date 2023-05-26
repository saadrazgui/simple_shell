#include "prnSd.h"
/**
* toknSD - char func Zid CHmin
* @buffer: param paramZid CHalhom
*
* Return: param parameZid CHhom
*/
char **toknSD(char *buffer)
{
	char *token;
	int i = 0, wordcount = 0;
	char *delimiter = " \n";
	char **av;

	wordcount = _sitstrSD(buffer);
	if (!wordcount)
		return (NULL);
	av = malloc((wordcount + 1) * sizeof(char *));
	if (av == NULL)
		exit(1);
	token = strtok(buffer, delimiter);
	while (token != NULL)
	{
		av[i] = _strupSD(token);
		token = strtok(NULL, delimiter);
		i++;
	}
	av[i] = NULL;
	return (av);
}
/**
* _sptPATSD - int func Dyl l3adZid CHamadi
* @SDstr: param waw paramZid CHalhom
*
* Return: ra9m of PATH 3Zid CH
*/
int _sptPATSD(char *SDstr)
{
	int i;
	int searchflag = 1;
	int wordcount = 0;

	for (i = 0; SDstr[i]; i++)
	{
		if (SDstr[i] != ':' && searchflag == 1)
		{
			wordcount += 1;
			searchflag = 0;
		}
		if (SDstr[i + 1] == ':')
		{
			searchflag = 1;
		}
	}
	return (wordcount);
}
/**
* _PAtstrcmpSD - int func dakcZid CHz loz
* @strSD1: param paramZid CHalhom
* @strSD2: param parZid CHalhom
*
* Return: 0 on succeSo ila
*/
int _PAtstrcmpSD(const char *strSD1, const char *strSD2)
{
	int i;

	for (i = 0; strSD2[i] != '='; i++)
	{
		if (strSD1[i] != strSD2[i])
			return (-1);
	}
	return (0);
}
/**
* _coctSD - char func Zid CHin
* @tmp: param parZid CHtre dyalhom
* @av: param parZid CHe dokil
* @tok: param pZid CHe maart
*
* Return: 0 on ilZid CH
*/
char *_coctSD(char *tmp, char **av, char *tok)
{
	int len = 0;

	_memsetSD(tmp, 0, 256);
	len = _stlnSD(tok) + _stlnSD(av[0]) + 2;
	_strctSD(tmp, tok);
	_strctSD(tmp, "/");
	_strctSD(tmp, av[0]);
	tmp[len - 1] = '\0';
	return (tmp);
}
