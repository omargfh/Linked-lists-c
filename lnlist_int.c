#include "lnlist_int.h"
#include <stdio.h>
#include <stdlib.h>

intlist *declare(int value)
{
	intlist *n = malloc(sizeof(intlist));
	n->number = value;
	n->next = NULL;
	return n;
}

int count(intlist *list)
{
	intlist *tmp = list;
	int count = 1;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	return count;
}

void lead(intlist *(*list), int value)
{
	intlist *n = declare(value);
	intlist *tmp = *list;
	n->next = tmp;
	*list = n;
}

void trail(intlist *(*list), int value)
{
	intlist *n = declare(value);
	intlist *tmp = *list;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = n;
}

void append(intlist *(*list), int value, int index)
{
	if (index == 0)
	{
		lead(list, value);
	}
	else
	{
		int range = count(*list);
		intlist *n = declare(value);
		intlist *prev = fetch_intlist(*list, index - 1);
		intlist *follow = fetch_intlist(*list, index);
		prev->next = n;
		n->next = follow;
	}

}

intlist *fetch_intlist(intlist *list, int index)
{
	intlist *tmp = list;
	if (index < count(list))
	{
		for (int i = 0; i < index; i++)
		{
			tmp = tmp->next;
		}
	}
	else
	{
		fprintf(stderr, "VALUE IN FETCH OUT OF RANGE, RETURNING POINTER TO LIST\n");
	}
	return tmp;
}

int fetch(intlist *list, int index)
{
	intlist *fetched = fetch_intlist(list, index);
	return fetched->number;
}

void delete(intlist *(*list), int index)
{
	if (index == 0)
	{
		intlist *follow = (*list)->next;
		*list = (*list)->next;
	}
	else
	{
		intlist *fetched = fetch_intlist(*list, index);
		intlist *prev, *follow;
		if (index > 0)
		{
			prev = fetch_intlist(*list, index - 1);
		}
		else
		{
			prev = *list;
		}
		int range = count(*list);
		if (index != range - 1 && index < range)
		{
			follow = fetch_intlist(*list, index + 1);
		}
		else
		{
			follow = NULL;
		}
		free(prev->next);
		prev->next = follow;
	}
}

int *list_to_array(intlist *list)
{
	int range = count(list);
	int *array = malloc(sizeof(int) * range);
	for (int i = 0; i < range; i++)
	{
		array[i] = fetch(list, i);
	}
	return array;
}

intlist *array_to_list(int array[], int range)
{
	intlist *list = declare(array[0]);
	for (int i = 1; i < range; i++)
	{
		trail(&list, array[i]);
	}
	return list;
}

void free_list(intlist *list)
{
	intlist *tmp = list;
    intlist *del;
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

void print(intlist *list)
{
	int range = count(list);
	printf("[");
	for (int i = 0; i < range; i++)
	{
		int value = fetch(list, i);
		printf("%d", value);
		if (i != range - 1)
		{
			printf(", ");
		}
	}
	printf("]\n");
}