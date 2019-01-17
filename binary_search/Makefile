search: main.o bsearch.o
	gcc -o search main.o bsearch.o

main.o: main.c
	gcc -c -g main.c

bsearch.o: bsearch.c
	gcc -c -g bsearch.c

clean:
	rm -f *.o search
