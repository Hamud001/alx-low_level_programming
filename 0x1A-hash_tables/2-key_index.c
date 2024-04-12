#include "hash_tables.h"
/**
 * key_index - unction that gives you the index of a key.
 * @key: key to generate index
 * @size: table size
 * Return: index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
unsigned long int hash, index;
hash = hash_djb2(key);
index = hash % size;
return (index);
}
