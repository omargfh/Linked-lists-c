#ifndef LNLIST_INT_H
#define LNLIST_INT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Defining type of linked list intlist
 */
typedef struct intlist
{
	int number;
	struct intlist *next;
}
intlist;

typedef intlist *intli;

/**
 * Declare a intlist and initializes its data value to "value"
 * and its pointer value "next" to NULL
 */
intlist *declare(int value);

/**
 * Returns an intger with the number of elements in a list
 */
int count(intlist *list);

/**
 * Appends a value as the first value in a list
 */
void lead(intlist *(*list), int value);

/**
 * Appends a value to the end of a list
 */
void trail(intlist *(*list), int value);

/**
 * Append a value at a certain place in the list;
 * this pushes all other intlists in the list to the right
 * of the newly-appened intlist
 */
void append(intlist *(*list), int value, int index);

/**
 * Returns the intlist at a certain index; returns
 * a pointer to the first element if index is out of
 * range and prints error message to the error stream
 */
intlist *fetch_intlist(intlist *list, int index);

/**
 * Returns the data value at a certain index; returns
 * a pointer to the first element if index is out of
 * range and prints error message to the error stream
 */
int fetch(intlist *list, int index);

/**
 * Converts a list into an array;
 * returns a pointer to the array
 */
int *list_to_array(intlist *list);

/**
 * Convers an array into a list;
 * returns a pointer to the list
 *
 */
intlist *array_to_list(int array[], int range);

/**
 * Frees allocated memory for list
 */
void free_list(intlist *list);

/**
 * Deletes/removes a value from a certain index
 */
void delete(intlist *(*list), int index);

/**
 * Prints a list to the stream
 */
void print(intlist *list);

#endif
