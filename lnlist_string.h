#ifndef LNLIST_STRING_H
#define LNLIST_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Defining type of linked list strlist
 */
typedef struct strlist
{
	char *word;
	struct strlist *next;
}
strlist;

typedef strlist *strli;

/**
 * strstrdeclare a strlist and initializes its data value to "value"
 * and its pointer value "next" to NULL
 */
strlist *strdeclare(char *value);

/**
 * Returns an intger with the number of elements in a list
 */
int strcount(strlist *list);

/**
 * Appends a value as the first value in a list
 */
void strlead(strlist *(*list), char *value);

/**
 * Appends a value to the end of a list
 */
void strtrail(strlist *(*list), char *value);

/**
 * Append a value at a certain place in the list;
 * this pushes all other strlists in the list to the right
 * of the newly-appened strlist
 */
void strappend(strlist *(*list), char *value, int index);

/**
 * Returns the strlist at a certain index; returns
 * a pointer to the first element if index is out of
 * range and prints error message to the error stream
 */
strlist *strfetch_strlist(strlist *list, int index);

/**
 * Returns the data value at a certain index; returns
 * a pointer to the first element if index is out of
 * range and prints error message to the error stream
 */
char *strfetch(strlist *list, int index);

/**
 * Converts a list into an array;
 * returns a pointer to the array
 */
char **strlist_to_array(strlist *list);

/**
 * Convers an array into a list;
 * returns a pointer to the list
 * Arrays must be free'd manually
 */
strlist *array_to_strlist(char *array[], int range);

/**
 * Frees allocated memory for list
 */
void free_strlist(strlist *list);

/**
 * Deletes/removes a value from a certain index
 */
void strdelete(strlist *(*list), int index);

/**
 * Prints a list to the stream
 */
void strprint(strlist *list);

#endif
