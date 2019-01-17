#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"


void grayscale(char* name, char* newname)
{
	int i, j;
	char* A;
	pixel **Image, Grey;
	header HeaderOfImage;
	FILE *f_input, *f_output;

	A = malloc(54 * sizeof(char));
	f_input = fopen(name, "rb");
	f_output = fopen(newname, "wb");
	fread(A, 54, 1, f_input);
	fwrite(A, 54, 1, f_output);
	fseek(f_input, 18, SEEK_SET);
	fread(&HeaderOfImage.WidthImage, 4, 1, f_input);
	fread(&HeaderOfImage.HeightImage, 4, 1, f_input);
	fseek(f_input, 28, SEEK_CUR);
	Image = (pixel**) malloc((HeaderOfImage.HeightImage + 1) * sizeof(pixel*));
	for(i = 1; i <= HeaderOfImage.HeightImage; i++)
	{
		Image[i] = (pixel*) malloc((HeaderOfImage.WidthImage + 1) * sizeof(pixel));
	}
	for(i = 1; i <= HeaderOfImage.HeightImage; i++)
	{
		for(j = 1; j <= HeaderOfImage.WidthImage; j++)
		{
			fread(&Image[i][j].B, 1, 1, f_input);
			fread(&Image[i][j].G, 1, 1, f_input);
			fread(&Image[i][j].R, 1, 1, f_input);
			Grey.R = (Image[i][j].R + Image[i][j].G + Image[i][j].B) / 3;
			Grey.G = Grey.R;
			Grey.B = Grey.G;
			fwrite(&Grey.R, 1, 1, f_output);
			fwrite(&Grey.G, 1, 1, f_output);
			fwrite(&Grey.B, 1, 1, f_output);
		}
		if((HeaderOfImage.WidthImage * 3) % 4 > 0)
		{
			fseek(f_input, (4 - ((HeaderOfImage.WidthImage * 3) % 4)), SEEK_CUR);
			fwrite("0", 1, (4 - (HeaderOfImage.WidthImage * 3) % 4), f_output);
		}
	}
	for(i = 0; i <= HeaderOfImage.HeightImage; i++)
	{
		free(Image[i]);
	}
	free(Image);
	free(A);
}
