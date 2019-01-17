#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

void main(void)
{
	char name[100], newname[100];
	int filter, i, j, c;
	header HeaderOfImage;
	FILE *f_input, *f_output;

	printf("%s\n", "Enter the name of the source image");
	scanf("%s", name);
	printf("%s\n", "Enter the name of the final image");
	scanf("%s", newname);
	do
	{
		printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n","Choose a filter", "1 - Mean 3*3", "2 - Mean 5*5", "3 - Gausses filter", "4 - Sobels filter on X", "5 - Sobels filter on Y", "6 - Grayscale", "7 - Sobels filter");
		scanf("%d",&filter);
	}while((filter < 1) || (filter > 7));
	if(filter == 1)
		tnt(name, newname);
	else if(filter == 2)
		fnf(name, newname);
	else if(filter == 3)
		Gauss(name, newname);
	else if(filter == 4)
		sobelx(name, newname);
	else if(filter == 5)
		sobely(name, newname);
	else if(filter == 6)
		grayscale(name, newname);
	else if(filter == 7)
		sobel(name, newname);
}
