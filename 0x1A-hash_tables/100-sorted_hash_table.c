#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
* shash_table_create - Creates a sorted hash table.
* @size: The size of new sorted hash table.
*
* Return: If an error occurs - NULL.
*         Otherwise - a pointer to the new sorted hash table.
*/
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *ht;
unsigned long int i;

if (size == 0)
return (NULL);

ht = malloc(sizeof(shash_table_t));
if (ht == NULL)
return (NULL);

ht->size = size;
ht->array = malloc(sizeof(shash_node_t *) * size);
if (ht->array == NULL)
{
free(ht);
return (NULL);
}

for (i = 0; i < size; i++)
ht->array[i] = NULL;

ht->shead = NULL;
ht->stail = NULL;

return (ht);
}

/**
* shash_table_set - Adds an element to a sorted hash table.
* @ht: A pointer to the sorted hash table.
* @key: The key to add - cannot be an empty string.
* @value: The value associated with key.
*
* Return: Upon failure - 0.
*         Otherwise - 1.
*/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
unsigned long int index;
shash_node_t *new_node, *temp;

if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
return (0);

index = key_index((const unsigned char *)key, ht->size);
temp = ht->array[index];

while (temp != NULL)
{
if (strcmp(temp->key, key) == 0)
{
free(temp->value);
temp->value = strdup(value);
if (temp->value == NULL)
return (0);
return (1);
}
temp = temp->next;
}

new_node = malloc(sizeof(shash_node_t));
if (new_node == NULL)
return (0);

new_node->key = strdup(key);
new_node->value = strdup(value);
if (new_node->key == NULL || new_node->value == NULL)
{
free(new_node->key);
free(new_node->value);
free(new_node);
return (0);
}
new_node->next = ht->array[index];
ht->array[index] = new_node;
insert_sorted_node(ht, new_node);
return (1);
}

/**
* shash_table_get - Retrieve the value associated with
*                   a key in a sorted hash table.
* @ht: A pointer to the sorted hash table.
* @key: The key to get the value of.
*
* Return: If the key cannot be matched - NULL.
*         Otherwise - the value associated with key in ht.
*/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
unsigned long int index;
shash_node_t *temp;

if (ht == NULL || key == NULL || *key == '\0')
return (NULL);

index = key_index((const unsigned char *)key, ht->size);
temp = ht->array[index];

while (temp != NULL)
{
if (strcmp(temp->key, key) == 0)
return (temp->value);
temp = temp->next;
}

return (NULL)
