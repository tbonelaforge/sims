all: adjacent_test.bin

adjacent_test.bin: adjacent_test.c adjacent.h adjacent.o
	gcc -I ./ adjacent_test.c adjacent.o -o adjacent_test.bin

adjacent.o: adjacent.c adjacent.h
	gcc -I ./ -c adjacent.c
