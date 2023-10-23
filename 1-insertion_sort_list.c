#include "sort.h"
/**
 * insertion_sort_list - .........
 * @list:unsorted list.
 * Return:void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *ptr;

	if (!list)
		return;
	current = (*list)->next;
	while (current != NULL && list)
	{
		ptr = current;
		while (ptr->prev != NULL && ptr->n < ptr->prev->n)
		{
			swap_nodes(list, ptr->prev, current);
			print_list(*list);
		}
		current = current->next;
	}
}
/**
 * swap_nodes - ..............
 * @list:unsorted list.
 * @node1:first pointer.
 * @node2:second pointer.
 * Return:void.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	node2->prev = node1->prev;
	node1->next = node2->next;
	if (node2->next)
		node2->next->prev = node1;
	node1->prev = node2;
	node2->next = node1;
	if (!node2->prev)
		*list = node2;
	else
		node2->prev->next = node2;
}
