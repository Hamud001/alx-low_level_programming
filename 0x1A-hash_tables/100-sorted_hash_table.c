#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Create a hash table.
 * @size: The size.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *hasht;
	unsigned long int i;

	hasht = malloc(sizeof(shash_table_t));
	if (hasht == NULL)
		return (NULL);

	hasht->size = size;
	hasht->array = malloc(sizeof(shash_node_t *) * size);
	if (hasht->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		hasht->array[i] = NULL;
	hasht->shead = NULL;
	hasht->stail = NULL;

	return (hasht);
}

/**
 * shash_table_set - Adds an element.
 * @ht: A pointer.
 * @key: The key to add - cannot be an empty string.
 * @value: The value.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int shash_table_set(shash_table_t *hasht, const char *key, const char *value)
{
	shash_node_t *new, *tmp;
	char *value_copy;
	unsigned long int index;

	if (hasht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, hasht->size);
	tmp = hasht->shead;
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = value_copy;
			return (1);
		}
		tmp = tmp->snext;
	}

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(value_copy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(value_copy);
		free(new);
		return (0);
	}
	new->value = value_copy;
	new->next = hasht->array[index];
	hasht->array[index] = new;

	if (hasht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		hasht->shead = new;
		hasht->stail = new;
	}
	else if (strcmp(hasht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = hasht->shead;
		hasht->shead->sprev = new;
		hasht->shead = new;
	}
	else
	{
		tmp = hasht->shead;
		while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
			tmp = tmp->snext;
		new->sprev = tmp;
		new->snext = tmp->snext;
		if (tmp->snext == NULL)
			hasht->stail = new;
		else
			tmp->snext->sprev = new;
		tmp->snext = new;
	}

	return (1);
}

/**
 * shash_table_get - Retrieve the value associated with
 *                   a key in a sorted hash table.
 * @hasht: A pointer.
 * @key: The key.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in hasht.
 */
char *shash_table_get(const shash_table_t *hasht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (hasht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, hasht->size);
	if (index >= hasht->size)
		return (NULL);

	node = hasht->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;

	return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - Prints a sorted Hash table.
 * @ht: A pointer.
 */
void shash_table_print(const shash_table_t *hasht)
{
	shash_node_t *node;

	if (hasht == NULL)
		return;

	node = hasht->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints in reverse order.
 * @ht: A pointer.
 */
void shash_table_print_rev(const shash_table_t *hasht)
{
	shash_node_t *node;

	if (hasht == NULL)
		return;

	node = hasht->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted ht.
 * @ht: A pointer to the ht.
 */
void shash_table_delete(shash_table_t *hasht)
{
	shash_table_t *head = hasht;
	shash_node_t *node, *tmp;

	if (hasht == NULL)
		return;

	node = hasht->shead;
	while (node)
	{
		tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}

	free(head->array);
	free(head);
}
