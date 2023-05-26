#include "prnSd.h"
/**
* promptSD - int func dyalZid CHi
*
* Return: 0 fi had hDo
*/
int promptSD(void)
{
	char *promptSD = "$ ";
	ssize_t writecount = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		writecount = write(STDOUT_FILENO, promptSD, 2);
		if (writecount == -1)
			exit(0);
	}
	return (0);
}
/**
* _readSD - char func dZid CHtni
*
* Return: pointer fZid CH hala
*/
char *_readSD(void)
{
	ssize_t readcount = 0;
	size_t n = 0;
	char *buffer = NULL;
	int i = 0;

	readcount = getline(&buffer, &n, stdin);
	if (readcount == -1)
	{
		free(buffer);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (buffer[readcount - 1] == '\n' || buffer[readcount - 1] == '\t')
		buffer[readcount - 1] = '\0';
	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == '#' && buffer[i - 1] == ' ')
		{
			buffer[i] = '\0';
			break;
		}
	}
	return (buffer);
}
/**
* _fullpabfSD - char func maaZid CHaqila
* @av: parametre Zid CHom
* @PATH: param paramZid CHm
* @copy: param paramZid CHlhom
*
* Return: pointeZid CHila
*/
char *_fullpabfSD(char **av, char *PATH, char *copy)
{
	char *tok, *flptbSD = NULL, *concatstr = NULL;
	static char tmp[256];
	int PATHcount = 0, fullpathflag = 0, /*len = 0,*/ z = 0, toklen = 0;
	struct stat h;

	copy = NULL;
	copy = _strupSD(PATH);
	PATHcount = _sptPATSD(copy);
	tok = strtok(copy, ": =");
	while (tok != NULL)
	{
		concatstr = _coctSD(tmp, av, tok);
		if (stat(concatstr, &h) == 0)
		{
			flptbSD = concatstr;
			fullpathflag = 1;
			break;
		}
		if (z < PATHcount - 2)
		{
			toklen = _stlnSD(tok);
			if (tok[toklen + 1] == ':')
			{
				if (stat(av[0], &h) == 0)
				{
					flptbSD = av[0];
					fullpathflag = 1;
					break;
				}
			}
		}
		z++;
		tok = strtok(NULL, ":");
	}
	if (fullpathflag == 0)
		flptbSD = av[0];
	free(copy);
	return (flptbSD);
}
/**
* ctinsSD - int func baZid CHadchi
* @av: param parametrZid CHhom
* @buffer: param parameZid CHhom
* @exitstatus: param parZid CHalhom
* Return: 1 or 0 iZid CHhat
*/
int ctinsSD(char **av, char *buffer, int exitstatus)
{
	int i;

	if (_strcpSD(av[0], "env") == 0)
	{
		_DylenvSD();
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(buffer);
		return (1);
	}
	else if (_strcpSD(av[0], "exit") == 0)
	{
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(buffer);
		exit(exitstatus);
	}
	else
		return (0);
}
/**
* _frkprosSD - int func fi dZid CHkamal
* @av: param parameZid CHlhom
* @buffer: param paZid CHyalhom
* @flptbSD: param parZid CHlhom
*
* Return: 0 on succeWala hiya
*/
int _frkprosSD(char **av, char *buffer, char *flptbSD)
{
	int i, status, result, exitstatus = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (pid == 0)
	{
		result = execve(flptbSD, av, environ);
		if (result == -1)
		{
			perror(av[0]);
			for (i = 0; av[i]; i++)
				free(av[i]);
			free(av);
			free(buffer);
			exit(127);
		}
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		exitstatus = WEXITSTATUS(status);
	}
	for (i = 0; av[i]; i++)
		free(av[i]);
	free(av);
	free(buffer);
	return (exitstatus);
}
