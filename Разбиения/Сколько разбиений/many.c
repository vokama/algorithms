#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int i, j, n, m;
	unsigned long **permuta, sum = 0;

	printf("Введите количество элементов и количество кусков в наибольшем разбиении\n");
	scanf("%d%d", &n , &m);

	permuta = malloc((n + 1) * sizeof(unsigned long *));
	for(i = 0; i <= n; i++)
		permuta[i] = malloc((m + 1) * sizeof(unsigned long));

	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= m && j <= i; j++)
		{
			if(i == j)
				permuta[i][j] = 1;
			else if(i == 0 || j == 0)
				permuta[i][j] = 0;
			else
				permuta[i][j] = permuta[i - 1][j - 1] + j * permuta[i - 1][j];
			printf("%ld ", permuta[i][j]);
		}
		printf("\n");
	}
	for(j = 0; j <= m; j++)
		sum += permuta[n][j];
	printf("\n%ld\n", sum);

	for(i = 0; i <= n; i++)
		free(permuta[i]);
	free(permuta);

	return 0;
}
