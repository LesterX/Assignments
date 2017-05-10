# Makefile 

asn4_1: bst.o main.o
	gcc -o asn4_1 bst.o main.o

main.o: main.c bst.h
	gcc -c main.c

bst.o: bst.c data.c bst.h data.h
	gcc -c bst.c data.c

clean:
	rm -f asn4_1 *.o core
