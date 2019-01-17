hsearch: main.o numerator.o hash_table.o pcg_basic.o
	gcc -o hsearch main.o numerator.o hash_table.o pcg_basic.o

main.o: main.c
	gcc -c -g main.c

numerator.o: numerator.c
	gcc -c -g numerator.c

hash_table.o: hash_table.c
	gcc -c -g hash_table.c

pcg_basic.o: pcg_basic.c
	gcc -c pcg_basic.c

clean:
	rm -f *.o hsearch
