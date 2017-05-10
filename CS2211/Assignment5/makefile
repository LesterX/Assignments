# Makefile for the main
mymatrix: main.o matrix.o bs_tree.o datatype.o
	gcc -o mymatrix main.o matrix.o bs_tree.o datatype.o
main.o: matrix.c matrix.h
	gcc -c main.c 
matrix.o: matrix.c matrix.h bs_tree.h
	gcc -c matrix.c
bs_tree.o: bs_tree.c bs_tree.h datatype.h
	gcc -c bs_tree.c
datatype.o: datatype.c datatype.h
	gcc -c datatype.c
clean:
	rm -f main *.o core mymatrix