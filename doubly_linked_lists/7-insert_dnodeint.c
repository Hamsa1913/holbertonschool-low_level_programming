#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to pointer of the head of the list
 * @idx: index where the new node should be added
 * @n: value for the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);

	/* Case 1: Insert at beginning */
	if (idx == 0)
		return (add_dnodeint(h, n));

	temp = *h;

	/* Traverse to node before index */
	while (temp != NULL && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	/* If index is out of range */
	if (temp == NULL)
		return (NULL);

	/* Case 2: Insert at end */
	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	/* Case 3: Insert in the middle */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = temp;
	new_node->next = temp->next;
	temp->next->prev = new_node;
	temp->next = new_node;

	return (new_node);
}

