#include "shltSD.h"


/**
 * _getenv - getsked liZodkthe global variable
 * @name: name ked liZodkl variable
 * Return: striked liZodkalue
 */
char *_getenv(const char *name)
{
	int i, j;
	char *value;

	if (!name)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
					break;

				j++;
			}
			if (name[j] == '\0')
			{
				value = (environ[i] + j + 1);
				return (value);
			}
		}
	}
	return (0);
}


/**
 * add_node_end_SD - adds a new node ked liZodkf a list_t list
 * @head: pointer to pointked liZodkked list
 * @str: pointer to striked liZodkrst node
 * Return: address of thked liZodklement/node
 */

list_pathSD *add_node_end_SD(list_pathSD **head, char *str)
{

	list_pathSD *tmp;
	list_pathSD *new;

	new = malloc(sizeof(list_pathSD));

	if (!new || !str)
	{
		return (NULL);
	}

	new->dirSD = str;

	new->p = '\0';
	if (!*head)
	{
		*head = new;
	}
	else
	{
		tmp = *head;

		while (tmp->p)
		{

			tmp = tmp->p;
		}

		tmp->p = new;
	}

	return (*head);
}


/**
 * linkpath - createked liZodkfor path directories
 * @path: strinked liZodklue
 * Return: pointer tked liZodkd linked list
 */
list_pathSD *linkpath(char *path)
{
	list_pathSD *head = '\0';
	char *token;
	char *cpath = _strdup(path);

	token = strtok(cpath, ":");
	while (token)
	{
		head = add_node_end_SD(&head, token);
		token = strtok(NULL, ":");
	}

	return (head);
}

/**
 * _whichSD - fiked liZodke of a filename
 * @filename: name ked liZodk command
 * @head: head of linkeked liZodkh directories
 * Return: pathname of ked liZodkNULL if no match
 */
char *_whichSD(char *filename, list_pathSD *head)
{
	struct stat st;
	char *string;

	list_pathSD *tmp = head;

	while (tmp)
	{

		string = concat_allSD(tmp->dirSD, "/", filename);
		if (stat(string, &st) == 0)
		{
			return (string);
		}
		free(string);
		tmp = tmp->p;
	}

	return (NULL);
}

/**
 * free_listSD - freked liZodka list_t
 *@head: pointeked liZodknked list
 */
void free_listSD(list_pathSD *head)
{
	list_pathSD *storage;

	while (head)
	{
		storage = head->p;
		free(head->dirSD);
		free(head);
		head = storage;
	}

}
