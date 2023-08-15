#include "sort.h"
listint_t *swap(listint_t **current, listint_t **sorted);
/**
 * insertion_sort_list - sorts doubley linked list
 * @list: list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	sorted = *list;
	current = (*list)->next;
	while (current != NULL)
	{
		if (sorted != NULL && current->n < sorted->n)
		{
			current = swap(&current, &sorted);
			sorted = current->prev;
			if (sorted == NULL)
				*list = current;
			print_list(*list);
			while (sorted != NULL && current->n < sorted->n)
			{
				current = swap(&current, &sorted);
				sorted = current->prev;
				if (sorted == NULL)
					*list = current;
				print_list(*list);
			}
		}
		else
		{
			sorted = current;
			current = sorted->next;
		}
	}
}


/**
 * swap - swap numbers in array
 * @current: pointer to a node in linked list
 * @sorted: pointer to a node in linked list
 * Return: pointer to current node
 */
listint_t *swap(listint_t **current, listint_t **sorted)
{
	listint_t *temp;

	temp = (*current)->next;
	if (*sorted != NULL)
		(*sorted)->next = temp;
	if (temp != NULL)
		temp->prev = *sorted;
	if (*current != NULL)
	{
		(*current)->next = *sorted;
		(*current)->prev = (*sorted)->prev;
	}
	if ((*sorted)->prev != NULL)
		(*sorted)->prev->next = *current;
	((*sorted)->prev) = *current;
	return (*current);
}
