#ifndef  LINKEDLIST_H
#define  LINKEDLIST_H

#include <stdlib.h>

typedef struct linkedlist linkedlist;

/**
 * Creates a new linked list.
 */
linkedlist * linkedlist_new(void);

/**
 * Returns the length of the linked list.
 */
size_t linkedlist_length(linkedlist * list);

/**
 * Add an element to the linked list.
 */
linkedlist * linkedlist_add(linkedlist * list, void * element);

#endif// LINKEDLIST_H

