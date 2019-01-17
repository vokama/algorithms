#include <stdio.h>

int main()
{
	int arr[1000000], x = 457896, i;

	for(i = 0; i < 1000000; i++)
	{
		arr[i] = i / 2;
	}

	if(bsearch(arr, 1000000, x) == -1)
		printf("В данном массиве не существует элементов, строго больших %d\n", x);
	else
		printf("Первый элемент, строго больший %d, имеет индекс %d\n", x, bsearch(arr, 1000000, x));

return 0;
}
