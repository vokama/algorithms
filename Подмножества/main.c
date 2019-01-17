#include <stdio.h>

int main()
{
	unsigned n, i, summand = 1;
	unsigned long sum = 0;

	printf("На сколько подмножеств (не считая пустого) можно разбить ваше множество? Введите количество его элементов и узнаете!\n");
	scanf("%u", &n);

	for(i = 1; i <= n; i++)
	{
		summand = summand * (n - i + 1) / i;
		sum += summand;
	}
	printf("%lu\n", sum);

	return 0;
}
