#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "hash_types.h"


int main(int argc, char *argv[])
{
	FILE *vocab;
	hashinfo info;
	char *str;
	int count, i;
	hashtable_t *hashtable;

	if(argc == 1)
		printf("Укажите имя файла в качестве аргумента программы\n");
	else if((vocab = fopen(argv[1], "r")) == NULL)
			printf("Такого файла не существует\n");
	else
	{
		printf("Хешируем...\n");
		info = numerator();
		hashtable = ht_create(info.m);
		do
		{
			fseek(vocab, -1, SEEK_CUR);
			count = 0;
			while(fgetc(vocab) != 10)
			{
				count++;
			}
			str = malloc((count + 1) * sizeof(char));
			fseek(vocab, -(count + 1), SEEK_CUR);
			fgets(str, count + 1, vocab);
			ht_set(hashtable, str, count, info);
			free(str);
			fseek(vocab, 1, SEEK_CUR);
		}while(fgetc(vocab) != EOF);
		str = malloc(134217728 * sizeof(char));  //128 Mb

		printf("Введите строку. Для завершения программы введите exit\n");
		while(1)
		{
			i = 0;
			do
			{
				str[i] = fgetc(stdin);
			}while(str[i++] != 10);
			str[--i] = 0;
			if(strncmp(str, "exit", 4) == 0)
				break;
			if(ht_get(hashtable, str, i, info) == 0)
				printf("NO\n");
			else
				printf("YES\n");
		}
		free(hashtable->table);
		free(hashtable);
		free(str);
	}

return 0;
}
