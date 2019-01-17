#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, k, n, m, *arr, max = 0, sum = 0, *f;
	FILE *ayk;

	printf("Введите количество элементов и количество кусков в наибольшем разбиении\n");
	scanf("%d%d", &n, &m);
	arr = malloc(n * sizeof(int));
	f = malloc((m - 1) * sizeof(int));
	f[0] = 0;

	for(i = 1; i < m - 1; i++)
		f[i] = n;
	ayk = fopen("a lot", "w");
	for(i = 0; i < n; i++)
	{
		arr[i] = 1;
		fprintf(ayk, "%d", arr[i]);
	}
	fprintf(ayk, "\n");

	for(i = 1; i < m; i++)
		max += i;
	for(i = m; i <= n; i++)
		max += m;
	while(sum != max)
	{
		for(i = n - 1; i >= 0; i--)
		{
			if(arr[i] < m)
			{
				if(i > f[arr[i] - 1])
				{
					arr[i]++;
					for(k = i + 1; k < n; k++)
						arr[k] = 1;
					if(arr[i] != m)
					{
						if(i < f[arr[i] - 1])
							f[arr[i] - 1] = i;
					}
					for(k = 0; arr[i] + k < m - 1; k++)
					{
						if(i < f[arr[i] + k])
							f[arr[i] + k] = n;
					}
					break;
				}
			}
		}
		sum = 0;
		for(i = 0; i < n; i++)
		{
			fprintf(ayk, "%d", arr[i]);
			sum += arr[i];
		}
		fprintf(ayk, "\n");
	}
	free(arr);
	free(f);

	return 0;
}
