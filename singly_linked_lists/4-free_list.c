#include "lists.h"
#include <string.h>

/**
 * free_list - frees a list_t list
 * @head: pointer to the list to free
 *
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}

