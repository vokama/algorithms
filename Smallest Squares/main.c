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

float scalar_mult_columns(float** a, int k1, int k2, int n)  //pointer to 2-dimentional array, 2 columns that we wish to multiply, number of rows
{
	int i;
	float sum = 0;

	for(i = 0; i < n; i++)
	{
		sum += a[i][k1] * a[i][k2];
	}

	return sum;
}

int main()
{
	int n, m, i, j, k;
	float **a, **b, *x, coeff, sum;

	scanf("%d%d", &n, &m);
	if(n < m)
		return 0;
	x = (float*) malloc(m * sizeof(float));
	b = (float**) malloc(m * sizeof(float*));
	for(i = 0; i < m; i++)
		b[i] = (float*) malloc((m + 1) * sizeof(float));
	a = (float**) malloc(n * sizeof(float*));
	for(i = 0; i < n; i++)
		a[i] = (float*) malloc((m + 1) * sizeof(float));
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m + 1; j++)
			scanf("%f", &a[i][j]);
	}
	for(i = 0; i < m; i++)
	{
		for(j = i; j < m + 1; j++)
		{
			b[i][j] = scalar_mult_columns(a, i, j, n);
		}
	}
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < i; j++)
		{
			b[i][j] = b[j][i];
		}
	}

	/* now we will Gauss the hell out of b */

	for(i = 0; i < m - 1; i++)  //go down
	{
		if(!b[i][i])  //swapping rows
		{
			for(k = i + 1; k < m; k++)
			{
				if(b[k][i])
					break;
			}
			if(k != m)
				arr_swap(&b[i], &b[k]);
		}
		for(k = i + 1; k < m; k++)
		{
			if(!b[i][i])  //which means that all b[?][i] == 0
				coeff = 1;
			else
				coeff = b[k][i] / b[i][i];
			for(j = i; j < m + 1; j++)
				b[k][j] -= b[i][j] * coeff;
		}
	}
	for(i = m - 1; i >= 0; i--)  //go up
	{
		sum = 0;
		for(j = i + 1; j < m; j++)
		{
			if(x[j] != x[j])  //nan
			{
				if(b[i][j])
				{
					x[i] = x[j];
					break;
				}
			}
			else
				sum += x[j] * b[i][j];
		}
		if(j == m)
		{
			x[i] = (b[i][m] - sum) / b[i][i];
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
		for(i = 0; i < m; i++)
			printf("%f ", x[i]);
		printf("\n");
	}


	for(i = 0; i < m; i++)
		free(b[i]);
	for(i = 0; i < n; i++)
		free(a[i]);
	free(b);
	free(a);
	free(x);

	return 0;
}
