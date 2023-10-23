#include "sort.h"
/**
 * swap_nodes - ..............
 * @list:unsorted list.
 * @node1:first pointer.
 * @node2:second pointer.
 * Return:void.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
	if (!node2->prev)
		*list = node2;
	print_list(*list);
}
/**
 * insertion_sort_list - .........
 * @list:unsorted list.
 * Return:void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		prev = current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			swap_nodes(list, prev, current);
			prev = current->prev;
		}
	current = current->next;
	}
}
