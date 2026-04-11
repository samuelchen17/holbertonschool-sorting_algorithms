#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - insertion sort a doubly linked list in asc order
 * @list: pointer to head of list
 */

void insertion_sort_list(listint_t **list)
{
listint_t *current, *next, *prev;

/* edge case check */
if (!list || !*list || !(*list)->next)
return;

/* start on 2nd node */
current = (*list)->next;
while (current)
{
next = current->next;

/* while prev exists and current n < prev n*/
while (current->prev && current->n < current->prev->n)
{
prev = current->prev;

/* connect current prev to next */
prev->next = current->next;
/* if not tail */
if (current->next)
current->next->prev = prev;

/* move current before prev */
current->next = prev;
current->prev = prev->prev;

/* if not head */
if (prev->prev)
prev->prev->next = current;
else
/* update head */
*list = current;
prev->prev = current;

print_list(*list);
}

current = next;
}
}
