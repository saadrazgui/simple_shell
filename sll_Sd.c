#include "prnSd.h"
/**
* _strupSD - char func Zid CH deyalha
* @SDstr: param Zid CHre dyalhom
*
* Return: pointerZid CHt lihom
*/
char *_strupSD(char *SDstr)
{
	int i;
	char *dest_str;

	if (SDstr == NULL)
		return (NULL);
	for (i = 0; SDstr[i] != '\0'; i++)
		;
	dest_str = malloc(sizeof(char) * (i + 1));
	if (dest_str == NULL)
		return (NULL);
	for (i = 0; SDstr[i] != '\0'; i++)
	{
		dest_str[i] = SDstr[i];
	}
	dest_str[i] = '\0';
	return (dest_str);
}
/**
* _sitstrSD - int func fiZid CH mlin
* @SDstr: param maZid CHch
*
* Return: param paraZid CHyalhom
*/
int _sitstrSD(char *SDstr)
{
	int i;
	int searchflag = 1;
	int wordcount = 0;

	for (i = 0; SDstr[i]; i++)
	{
		if (SDstr[i] != ' ' && searchflag == 1)
		{
			wordcount += 1;
			searchflag = 0;
		}
		if (SDstr[i + 1] == ' ')
			searchflag = 1;
	}
	return (wordcount);
}
/**
* _strcpSD - int func tZid CHg 3lina
* @strSD1: param paramZid CHalhom
* @strSD2: param paramZid CHalhom
* Return: int cZid CHam
*/
int _strcpSD(const char *strSD1, const char *strSD2)
{
	while ((*strSD1 != '\0' && *strSD2 != '\0') && *strSD1 == *strSD2)
	{
		strSD1++;
		strSD2++;
	}
	if (*strSD1 == *strSD2)
		return (0);
	else
		return (*strSD1 - *strSD2);
}
/**
* _strctSD - char func awdZid CH ghadi
* @dest: param paramZid CHyalhom
* @src: param paramZid CHalhom
* i - param parametrZid CHhom jdid
* j - param jZid CHhi
* Return: char chZid CH hada
*/
char *_strctSD(char *dest, char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++, i++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}
/**
* _stlnSD - int func bazZid CHyl
* @s: param Zid CH khadma
* i - param Zid CH parametre dyalhom
* Return: int waZid CH
*/
int _stlnSD(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}
