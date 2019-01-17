#include <stdlib.h>
#include <string.h>
#include "hash_types.h"

hashtable_t *ht_create(unsigned long size)
{
	hashtable_t *hashtable = NULL;
	int i;

	if(size < 1)
		return NULL;

	if((hashtable = malloc(sizeof(hashtable_t))) == NULL)
		return NULL;

	if((hashtable->table = malloc(sizeof(entry_t *) * size)) == NULL)
		return NULL;

	for(i = 0; i < size; i++)
		hashtable->table[i] = NULL;

	hashtable->size = size;

	return hashtable;
}

int ht_hash(char *key, int key_length, hashinfo info)
{
	unsigned long h = key[0];
	int i;


	for(i = 1; i < key_length; i++)
	{
		h = h * (info.a_str) + key[i];
		h = (h & info.p) + (h>>info.ppower);  // h mod p
		while(h >= info.p)
			h -= info.p;
	}

	h = (info.a_int * h + info.b_int)>>(info.w - info.M);

	return h;
}

entry_t *ht_newpair(char *key)
{
	entry_t *newpair;

	if((newpair = malloc(sizeof(entry_t))) == NULL)
		return NULL;

	if((newpair->key = strdup(key)) == NULL)
		return NULL;


	newpair->next = NULL;

	return newpair;
}

void ht_set(hashtable_t *hashtable, char *key, int key_length, hashinfo info)
{
	unsigned long bin = 0;
	entry_t *newpair = NULL;
	entry_t *next = NULL;

	bin = ht_hash(key, key_length, info);

	next = hashtable->table[bin];

	while(next != NULL && next->key != NULL && strcmp(key, next->key) != 0)
		next = next->next;

	if(next == NULL || next->key == NULL || strcmp(key, next->key) != 0)
	{
		newpair = ht_newpair(key);

		newpair->next = hashtable->table[bin];
		hashtable->table[bin] = newpair;
	}
}

char ht_get(hashtable_t *hashtable, char *key, int key_length, hashinfo info)
{
	int bin = 0;
	entry_t *pair;

	bin = ht_hash(key, key_length, info);

	pair = hashtable->table[bin];
	while(pair != NULL && pair->key != NULL && strcmp(key, pair->key) != 0)
		pair = pair->next;

	if(pair == NULL || pair->key == NULL || strcmp(key, pair->key) != 0)
		return 0;

	else
		return 1;
}
