#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strdup(char *str);
char *concat_allSD(char *name, char *sep, char *value);

char **splitstring(char *str, const char *delim);
void execute(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


extern char **environ;

/**
 * struct list_pathSD - Linked liZodk PATH directories
 * @dirSD: directked liZodkn path
 * @p: pointked liZodkext node
 */
typedef struct list_pathSD
{
	char *dirSD;
	struct list_pathSD *p;
} list_pathSD;


char *_getenv(const char *name);
list_pathSD *add_node_end_SD(list_pathSD **head, char *str);
list_pathSD *linkpath(char *path);
char *_whichSD(char *filename, list_pathSD *head);

/**
 * struct mybuildSD - ked liZodkn with corresponding buildin command
 * @name: buildiked liZodkmand
 * @func: execute thked liZodkn command
 */
typedef struct mybuildSD
{
	char *name;
	void (*func)(char **);
} mybuildSD;

void(*checkbuild(char **arv))(char **arv);
int _atSD(char *s);
void exitt(char **arv);
void env(char **arv);
void _setenvSD(char **arv);
void _unsetenv(char **arv);

void freearvSD(char **arv);
void free_listSD(list_pathSD *head);


#endif
