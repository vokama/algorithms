typedef struct{

	unsigned long a_str;
	unsigned long a_int;
	unsigned long b_int;
	unsigned long p;
	unsigned long m;
	char w;
	char M;
	char ppower;
}hashinfo;

struct entry_s {
	char *key;
	struct entry_s *next;
};

typedef struct entry_s entry_t;

struct hashtable_s {
	unsigned long size;
	struct entry_s **table;
};

typedef struct hashtable_s hashtable_t;

hashinfo numerator(void);
hashtable_t *ht_create(unsigned long);
void ht_set(hashtable_t *, char *, int, hashinfo);
char ht_get(hashtable_t *, char *, int, hashinfo);
