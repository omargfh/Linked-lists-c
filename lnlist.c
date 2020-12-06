#include "lnlist.h"
#include <stdio.h>
#include <stdlib.h>

node *declare(int value)
{
	node *n = malloc(sizeof(node));
	n->number = value;
	n->next = NULL;
	return n;
}

int count(node *list)
{
	node *tmp = list;
	int count = 1;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	return count;
}

void lead(node *(*list), int value)
{
	node *n = declare(value);
	node *tmp = *list;
	n->next = tmp;
	list = &n;
}

void trail(node *(*list), int value)
{
	node *n = declare(value);
	node *tmp = *list;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = n;
}

void append(node *(*list), int value, int index)
{
	if (index == 0)
	{
		lead(list, value);
	}
	else
	{
		int range = count(*list);
		node *n = declare(value);
		node *prev = fetch_node(*list, index - 1);
		node *follow = fetch_node(*list, index);
		prev->next = n;
		n->next = follow;
	}

}

node *fetch_node(node *list, int index)
{
	node *tmp = list;
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

int fetch(node *list, int index)
{
	node *fetched = fetch_node(list, index);
	return fetched->number;
}

void delete(node *(*list), int index)
{
	if (index == 0)
	{
		node *follow = (*list)->next;
		list = &(*list)->next;
	}
	else
	{
		node *fetched = fetch_node(*list, index);
		node *prev, *follow;
		if (index > 0)
		{
			prev = fetch_node(*list, index - 1);
		}
		else
		{
			prev = *list;
		}
		int range = count(*list);
		if (index != range - 1 && index < range)
		{
			follow = fetch_node(*list, index + 1);
		}
		else
		{
			follow = NULL;
		}
		free(prev->next);
		prev->next = follow;
	}
}

int *list_to_array(node *list)
{
	int range = count(list);
	int *array = malloc(sizeof(int) * range);
	for (int i = 0; i < range; i++)
	{
		array[i] = fetch(list, i);
	}
	return array;
}

node *array_to_list(int array[], int range)
{
	node *list = declare(array[0]);
	for (int i = 1; i < range; i++)
	{
		trail(&list, array[i]);
	}
	return list;
}

void free_list(node *list)
{
	int range = count(list);
	node *tmp = list;
	node *del;
	for (int i = 0; i < range; i++)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
}

void sort(node *(*list))
{
	int range = count(*list);
	int *array = malloc(sizeof(int) * range);
	array = list_to_array(*list);
	free(*list);
	qsort(array, range, sizeof(int), cmpr);
	*list = array_to_list(array, range);
	free(array);
	list = &(*list);
}

int cmpr(const void *a, const void *b)
{
	int *x = (int *) a;
	int *y = (int *) b;
	return *x - *y;
}

void print(node *list)
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