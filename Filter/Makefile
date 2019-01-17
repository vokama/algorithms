cebrogram: main.o grayscale.o sobelx.o sobely.o tnt.o fnf.o Gauss.o sobel.o
	gcc -o cebrogram -std=c99 -g main.o grayscale.o sobelx.o sobely.o tnt.o fnf.o Gauss.o sobel.o -lm

main.o: main.c
	gcc -c main.c

grayscale.o: grayscale.c
	gcc -c grayscale.c

sobelx.o: sobelx.c
	gcc -c sobelx.c

sobely.o: sobely.c
	gcc -c sobely.c

tnt.o: tnt.c
	gcc -c tnt.c

fnf.o: fnf.c
	gcc -c fnf.c

Gauss.o: Gauss.c
	gcc -c Gauss.c

sobel.o: sobel.c
	gcc -c sobel.c

clean:
	rm -f *.o *.bmp cebrogram
