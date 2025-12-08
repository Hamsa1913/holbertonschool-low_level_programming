#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 * @ht: Pointer to the hash table
 *
 * Description: Format example:
 * {'key': 'value', 'key2': 'value2'}
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	int comma = 0;

	if (ht == NULL)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			if (comma)
				printf(", ");

			printf("'%s': '%s'", node->key, node->value);
			comma = 1;
			node = node->next;
		}
	}

	printf("}\n");
}

