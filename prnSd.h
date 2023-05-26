#ifndef prnSd_H
#define prnSd_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

extern char **environ;

int promptSD(void);
char *_readSD(void);
char *_fullpabfSD(char **av, char *PATH, char *copy);
int ctinsSD(char **av, char *buffer, int exitstatus);
int _frkprosSD(char **av, char *buffer, char *flptbSD);


char *_strupSD(char *SDstr);
int _sitstrSD(char *SDstr);
int _strcpSD(const char *strSD1, const char *strSD2);
char *_strctSD(char *dest, char *src);
int _stlnSD(char *s);

char **toknSD(char *buffer);
int _sptPATSD(char *SDstr);
int _PAtstrcmpSD(const char *strSD1, const char *strSD2);
char *_coctSD(char *tmp, char **av, char *tok);

char *_gtenvSD(const char *name);
int _DylenvSD(void);
void _putsSaD(char *SDstr);
int _naptchSD(char c);
char *_memsetSD(char *s, char b, unsigned int n);

#endif
