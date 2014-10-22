all: permutation_iterator_test.bin

permutation_iterator_test.bin: ./permutation_iterator_test.c ./permutation_iterator.h permutation_iterator.o mixed_radix
	gcc -I ./ -I ../mixed_radix/ ./permutation_iterator_test.c ./permutation_iterator.o ../mixed_radix/mixed_radix.o -o ./permutation_iterator_test.bin

permutation_iterator.o: ./permutation_iterator.c ./permutation_iterator.h
	gcc -I ./ -I ../mixed_radix/ -c ./permutation_iterator.c

.PHONY: mixed_radix

mixed_radix:
	cd ../mixed_radix; make
