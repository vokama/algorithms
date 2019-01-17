#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"


void Gauss(char* name, char* newname)
{
	int i, j;
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
	for(i = 1; i <= HeaderOfImage.HeightImage; i++)
	{
		Image[i] = (pixel*) malloc((HeaderOfImage.WidthImage + 1) * sizeof(pixel));
		NewImage[i] = (pixel*) malloc((HeaderOfImage.WidthImage + 1) * sizeof(pixel));
	}
	for(i = 1; i <= HeaderOfImage.HeightImage; i++)
	{
		for(j = 1; j <= HeaderOfImage.WidthImage; j++)
		{
			fread(&Image[i][j].B, 1, 1, f_input);
			fread(&Image[i][j].G, 1, 1, f_input);
			fread(&Image[i][j].R, 1, 1, f_input);
		}
		if((HeaderOfImage.WidthImage * 3) % 4 > 0)
			fseek(f_input, (4 - ((HeaderOfImage.WidthImage * 3) % 4)), SEEK_CUR);
	}
	for(i = 3; i <= HeaderOfImage.HeightImage - 2; i++)
	{
		for(j = 3; j <= HeaderOfImage.WidthImage - 2; j++)
		{
			NewImage[i][j].B = Image[i - 2][j - 2].B * 0.000789 + Image[i - 2][j - 1].B * 0.006581 + Image[i - 2][j].B * 0.013347 + Image[i - 2][j + 1].B * 0.006581 + Image[i - 2][j + 2].B * 0.000789 + Image[i - 1][j - 2].B * 0.006581 + Image[i - 1][j - 1].B * 0.054901 + Image[i - 1][j].B * 0.111345 + Image[i - 1][j + 1].B * 0.054901 + Image[i - 1][j + 2].B * 0.006581 + Image[i][j - 2].B * 0.013347 + Image[i][j - 1].B * 0.111345 + Image[i][j].B * 0.225821 + Image[i][j + 1].B * 0.111345 + Image[i][j + 2].B * 0.013347 + Image[i + 1][j - 2].B * 0.006581 + Image[i + 1][j - 1].B * 0.054901 + Image[i + 1][j].B * 0.111345 + Image[i + 1][j + 1].B * 0.054901 + Image[i + 1][j + 2].B * 0.006581 + Image[i + 2][j - 2].B * 0.000789 + Image[i + 2][j - 1].B * 0.006581 + Image[i + 2][j].B * 0.013347 + Image[i + 2][j + 1].B * 0.006581 + Image[i + 2][j + 2].B * 0.000789;
			NewImage[i][j].G = Image[i - 2][j - 2].G * 0.000789 + Image[i - 2][j - 1].G * 0.006581 + Image[i - 2][j].G * 0.013347 + Image[i - 2][j + 1].G * 0.006581 + Image[i - 2][j + 2].G * 0.000789 + Image[i - 1][j - 2].G * 0.006581 + Image[i - 1][j - 1].G * 0.054901 + Image[i - 1][j].G * 0.111345 + Image[i - 1][j + 1].G * 0.054901 + Image[i - 1][j + 2].G * 0.006581 + Image[i][j - 2].G * 0.013347 + Image[i][j - 1].G * 0.111345 + Image[i][j].G * 0.225821 + Image[i][j + 1].G * 0.111345 + Image[i][j + 2].G * 0.013347 + Image[i + 1][j - 2].G * 0.006581 + Image[i + 1][j - 1].G * 0.054901 + Image[i + 1][j].G * 0.111345 + Image[i + 1][j + 1].G * 0.054901 + Image[i + 1][j + 2].G * 0.006581 + Image[i + 2][j - 2].G * 0.000789 + Image[i + 2][j - 1].G * 0.006581 + Image[i + 2][j].G * 0.013347 + Image[i + 2][j + 1].G * 0.006581 + Image[i + 2][j + 2].G * 0.000789;
			NewImage[i][j].R = Image[i - 2][j - 2].R * 0.000789 + Image[i - 2][j - 1].R * 0.006581 + Image[i - 2][j].R * 0.013347 + Image[i - 2][j + 1].R * 0.006581 + Image[i - 2][j + 2].R * 0.000789 + Image[i - 1][j - 2].R * 0.006581 + Image[i - 1][j - 1].R * 0.054901 + Image[i - 1][j].R * 0.111345 + Image[i - 1][j + 1].R * 0.054901 + Image[i - 1][j + 2].R * 0.006581 + Image[i][j - 2].R * 0.013347 + Image[i][j - 1].R * 0.111345 + Image[i][j].R * 0.225821 + Image[i][j + 1].R * 0.111345 + Image[i][j + 2].R * 0.013347 + Image[i + 1][j - 2].R * 0.006581 + Image[i + 1][j - 1].R * 0.054901 + Image[i + 1][j].R * 0.111345 + Image[i + 1][j + 1].R * 0.054901 + Image[i + 1][j + 2].R * 0.006581 + Image[i + 2][j - 2].R * 0.000789 + Image[i + 2][j - 1].R * 0.006581 + Image[i + 2][j].R * 0.013347 + Image[i + 2][j + 1].R * 0.006581 + Image[i + 2][j + 2].R * 0.000789;
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
	}
	free(Image);
	free(NewImage);
	free(A);
}
