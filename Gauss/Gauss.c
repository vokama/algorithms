#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arr_swap(float **arr1, float **arr2)
{
	float *arr3;

	arr3 = *arr1;
	*arr1 = *arr2;
	*arr2 = arr3;
}

int main()
{
	int n, m, i, j, k, bound;
	float **a, *x, coeff, sum;

	/* getting sizes of rows and columns, allocating memory and getting values */
	scanf("%d%d", &n, &m);
	x = (float*) malloc(m * sizeof(float));
	a = (float**) malloc(n * sizeof(float*));
	for(i = 0; i < n; i++)
		a[i] = (float*) malloc((m + 1) * sizeof(float));
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m + 1; j++)
			scanf("%f", &a[i][j]);
	}
	if(n < m)
		bound = n - 1;
	else if(n > m)
		bound = m;
	else
		bound = n - 1;
	for(i = 0; i < bound; i++)  //go down
	{
		if(!a[i][i])  //swapping rows
		{
			for(k = i + 1; k < n; k++)
			{
				if(a[k][i])
					break;
			}
			if(k != n)
				arr_swap(&a[i], &a[k]);
		}
		for(k = i + 1; k < n; k++)
		{
			if(!a[i][i])  //which means that all a[?][i] == 0
				coeff = 1;
			else
				coeff = a[k][i] / a[i][i];
			for(j = i; j < m + 1; j++)
				a[k][j] -= a[i][j] * coeff;
		}
	}

	if(n < m)
	{
		for(i = n - 1; i >= 0; i--)  //go up
		{
			if(a[i][m])
			{
				for(j = i; j < m; j++)
				{
					if(a[i][j])
						break;
				}
				if(j == m)
				{
					printf("NO\n");
					break;
				}
			}
		}
		if(i == -1)
			printf("INF\n");
	}
	else if(n > m)
	{
		for(i = n - 1; i > m - 1; i--)  //go up
		{
			if(a[i][m])
				break;
		}
		if(i != m - 1)
			printf("NO\n");
		else
		{
			while(i >= 0)
			{
				sum = 0;
				for(j = i + 1; j < m; j++)
				{
					if(x[j] != x[j])  //nan
					{
						if(a[i][j])
						{
							x[i] = x[j];
							break;
						}
					}
					else
						sum += x[j] * a[i][j];
				}
				if(j == m)
				{
					x[i] = (a[i][m] - sum) / a[i][i];
					if(isinf(x[i]))
						break;
				}
				i--;
			}
			if(i >= 0)
				printf("NO\n");
			else if(x[0] != x[0])
				printf("INF\n");
			else
			{
				printf("YES\n");
				for(i = 0; i < m; i++)
					printf("%f ", x[i]);
				printf("\n");
			}
		}
	}
	else
	{
		for(i = n - 1; i >= 0; i--)  //go up
		{
			sum = 0;
			for(j = i + 1; j < m; j++)
			{
				if(x[j] != x[j])  //nan
				{
					if(a[i][j])
					{
						x[i] = x[j];
						break;
					}
				}
				else
					sum += x[j] * a[i][j];
			}
			if(j == m)
			{
				x[i] = (a[i][m] - sum) / a[i][i];
				if(isinf(x[i]))
					break;
			}
		}
		if(i >= 0)
			printf("NO\n");
		else if(x[0] != x[0])
			printf("INF\n");
		else
		{
			printf("YES\n");
			for(i = 0; i < m; i++)
				printf("%f ", x[i]);
			printf("\n");
		}
	}

	free(x);
	for(i = 0; i < n; i++)
		free(a[i]);
	free(a);

	return 0;
}
