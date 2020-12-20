#ifndef LNLIST_H
#define LNLIST_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Defining type of linked list node
 */
typedef struct node
{
	int number;
	struct node *next;
}
node;

/**
 * Declare a node and initializes its data value to "value"
 * and its pointer value "next" to NULL
 */
node *declare(int value);

/**
 * Returns an intger with the number of elements in a list
 */
int count(node *list);

/**
 * Appends a value as the first value in a list
 */
void lead(node *(*list), int value);

/**
 * Appends a value to the end of a list
 */
void trail(node *(*list), int value);

/**
 * Append a value at a certain place in the list;
 * this pushes all other nodes in the list to the right
 * of the newly-appened node
 */
void append(node *(*list), int value, int index);

/**
 * Returns the node at a certain index; returns
 * a pointer to the first element if index is out of
 * range and prints error message to the error stream
 */
node *fetch_node(node *list, int index);

/**
 * Returns the data value at a certain index; returns
 * a pointer to the first element if index is out of
 * range and prints error message to the error stream
 */
int fetch(node *list, int index);

/**
 * Converts a list into an array;
 * returns a pointer to the array
 */
int *list_to_array(node *list);

/**
 * Convers an array into a list;
 * returns a pointer to the list
 */
node *array_to_list(int array[], int range);

/**
 * Sorts a list in an ascending order
 */
void sort(node *(*list));

/**
 * IMPT FOR SORTING
 * Compares two values;
 * returns -1 if b comes before a
 * returns 0 if a and b are equal
 * returns 1 if a comes before b
 */
int cmpr(const void *a, const void *b);

/**
 * Frees allocated memory for list
 */
void free_list(node *list);

/**
 * Deletes/removes a value from a certain index
 */
void delete(node *(*list), int index);

/**
 * Prints a list to the stream
 */
void print(node *list);

#endif
