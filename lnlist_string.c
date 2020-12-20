#include "lnlist_string.h"
#include <stdio.h>
#include <stdlib.h>

strlist *strdeclare(char *value)
{
	strlist *n = malloc(sizeof(strlist));
	n->word = value;
	n->next = NULL;
	return n;
}

int strcount(strlist *list)
{
	strlist *tmp = list;
	int strcount = 1;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		strcount++;
	}
	return strcount;
}

void strlead(strlist *(*list), char *value)
{
	strlist *n = strdeclare(value);
	strlist *tmp = *list;
	n->next = tmp;
	*list = n;
}

void strtrail(strlist *(*list), char *value)
{
	strlist *n = strdeclare(value);
	strlist *tmp = *list;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = n;
}

void strappend(strlist *(*list), char *value, int index)
{
	if (index == 0)
	{
		strlead(list, value);
	}
	else
	{
		int range = strcount(*list);
		strlist *n = strdeclare(value);
		strlist *prev = strfetch_strlist(*list, index - 1);
		strlist *follow = strfetch_strlist(*list, index);
		prev->next = n;
		n->next = follow;
	}

}

strlist *strfetch_strlist(strlist *list, int index)
{
	strlist *tmp = list;
	if (index < strcount(list))
	{
		for (int i = 0; i < index; i++)
		{
			tmp = tmp->next;
		}
	}
	else
	{
		fprintf(stderr, "VALUE IN strfetch OUT OF RANGE, RETURNING POINTER TO LIST\n");
	}
	return tmp;
}

char *strfetch(strlist *list, int index)
{
	strlist *strfetched = strfetch_strlist(list, index);
	return strfetched->word;
}

void strdelete(strlist *(*list), int index)
{
	if (index == 0)
	{
		strlist *follow = (*list)->next;
		*list = (*list)->next;
	}
	else
	{
		strlist *strfetched = strfetch_strlist(*list, index);
		strlist *prev, *follow;
		if (index > 0)
		{
			prev = strfetch_strlist(*list, index - 1);
		}
		else
		{
			prev = *list;
		}
		int range = strcount(*list);
		if (index != range - 1 && index < range)
		{
			follow = strfetch_strlist(*list, index + 1);
		}
		else
		{
			follow = NULL;
		}
		free(prev->next);
		prev->next = follow;
	}
}

char **strlist_to_array(strlist *list)
{
	int range = strcount(list);
	char **array = malloc(sizeof(int) * range);
	for (int i = 0; i < range; i++)
	{
		array[i] = strfetch(list, i);
	}
	return array;
}

strlist *array_to_strlist(char *array[], int range)
{
	strlist *list = strdeclare(array[0]);
	for (int i = 1; i < range; i++)
	{
		strtrail(&list, array[i]);
	}
	return list;
}

void free_strlist(strlist *list)
{
	strlist *tmp = list;
    strlist *del;
    int x = 0;
    while (x == 0)
    {
        del = tmp;
        if (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        else
        {
            x++;
        }
        free(del);
    }
}

void strprint(strlist *list)
{
	int range = strcount(list);
	printf("[");
	for (int i = 0; i < range; i++)
	{
		char *value = strfetch(list, i);
		printf("%s", value);
		if (i != range - 1)
		{
			printf(", ");
		}
	}
	printf("]\n");
}