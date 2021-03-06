#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "structures.h"


void sobelx(char* name, char* newname)
{
	int i, j, Gx, **Intensity;
	char* A;
	pixel **Image, **NewImage;
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
	NewImage = (pixel**) malloc((HeaderOfImage.HeightImage + 1) * sizeof(pixel*));
	Intensity = (int**) malloc((HeaderOfImage.HeightImage + 1) * sizeof(int*));
	for(i = 1; i <= HeaderOfImage.HeightImage; i++)
	{
		Image[i] = (pixel*) malloc((HeaderOfImage.WidthImage + 1) * sizeof(pixel));
		NewImage[i] = (pixel*) malloc((HeaderOfImage.WidthImage + 1) * sizeof(pixel));
		Intensity[i] = (int*) malloc((HeaderOfImage.WidthImage + 1) * sizeof(int));
	}
	for(i = 1; i <= HeaderOfImage.HeightImage; i++)
	{
		for(j = 1; j <= HeaderOfImage.WidthImage; j++)
		{
			fread(&Image[i][j].B, 1, 1, f_input);
			fread(&Image[i][j].G, 1, 1, f_input);
			fread(&Image[i][j].R, 1, 1, f_input);
			Intensity[i][j] = Image[i][j].B + Image[i][j].G + Image[i][j].R;
		}
		if((HeaderOfImage.WidthImage * 3) % 4 > 0)
			fseek(f_input, (4 - ((HeaderOfImage.WidthImage * 3) % 4)), SEEK_CUR);
	}
	for(i = 2; i <= HeaderOfImage.HeightImage - 1; i++)
	{
		for(j = 2; j <= HeaderOfImage.WidthImage - 1; j ++)
		{
			Gx = abs( - Intensity[i + 1][j - 1] + Intensity[i + 1][j + 1] - 2 * Intensity[i][j - 1] + 2 * Intensity[i][j + 1] - Intensity[i - 1][j - 1] + Intensity[i - 1][j + 1]);
			NewImage[i][j].B = Gx * 255 / 3060;
			NewImage[i][j].G = NewImage[i][j].B;
			NewImage[i][j].R = NewImage[i][j].G;
		}
	}
	for(i = 1; i <= HeaderOfImage.HeightImage; i++)
	{
		for(j = 1; j <= HeaderOfImage.WidthImage; j++)
		{
			fwrite(&NewImage[i][j].B, 1, 1, f_output);
			fwrite(&NewImage[i][j].G, 1, 1, f_output);
			fwrite(&NewImage[i][j].R, 1, 1, f_output);
		}
		if((HeaderOfImage.WidthImage * 3) % 4 > 0)
			fwrite("0", 1, 4 - ((HeaderOfImage.WidthImage * 3) % 4), f_output);
	}
	for(i = 0; i <= HeaderOfImage.HeightImage; i++)
	{
		free(Image[i]);
		free(NewImage[i]);
		free(Intensity[i]);
	}
	free(Image);
	free(NewImage);
	free(A);
	free(Intensity);
}
