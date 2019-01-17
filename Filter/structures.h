typedef struct header
{
	short bfType;
	short bfReserved1;
	short bfReserved2;
	short NumberOfPlanes;
	short BitOnPexel;
	int SizeBitMap;
	int bfSize;
	int bfOffBits;
	int WidthImage;
	int HeightImage;
	int TypeOfCompression;
	int SizeOfCompressionFile;
	int ResolutionOfWidth;
	int ResolutionOfHeight;
	int NumberOfColours;
	int ImportantColours;
}header;

typedef struct pixel
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
}pixel;
