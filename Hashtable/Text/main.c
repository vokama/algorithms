#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* war;
	char i = 0;

	war = fopen("WarPeace", "r+");
	do
	{
		i = fgetc(war);
		if(i == 32)
		{
			fseek(war, -1, SEEK_CUR);
			fputc(10, war);
		}
	}while(i != EOF);
}
