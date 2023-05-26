#include "prnSd.h"
/**
* main - int func kamZid CHwaqila
*
* Return: 0 on fZid CHah
*/
int main(void)
{
	char *flptbSD = NULL, *copy = NULL, *buffer = NULL;
	char *PATH = NULL;
	char **av;
	int exitstatus = 0;

	signal(SIGINT, SIG_IGN);
	PATH = _gtenvSD("PATH");
	if (PATH == NULL)
		return (-1);
	while (1)
	{
		av = NULL;
		promptSD();
		buffer = _readSD();
		if (*buffer != '\0')
		{
			av = toknSD(buffer);
			if (av == NULL)
			{
				free(buffer);
				continue;
			}
			flptbSD = _fullpabfSD(av, PATH, copy);
			if (ctinsSD(av, buffer, exitstatus) == 1)
				continue;
			exitstatus = _frkprosSD(av, buffer, flptbSD);
		}
		else
			free(buffer);
	}
	return (0);
}
