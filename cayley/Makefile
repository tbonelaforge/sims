all: cayley_test.bin

cayley_test.bin: cayley_test.c cayley.h cayley.o
	gcc -I ./ cayley_test.c cayley.o -o cayley_test.bin

cayley.o: cayley.c cayley.h
	gcc -I ./ -c cayley.c
