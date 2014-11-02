all: cycle_finder.bin cycle_finder_test.bin

cycle_finder.bin: ./cycle_finder.c cayley permutation_iterator mixed_radix
	gcc -I ./ -I ./cayley -I ./permutation_iterator -I ./mixed_radix ./cycle_finder.c ./cayley/cayley.o ./permutation_iterator/permutation_iterator.o ./mixed_radix/mixed_radix.o -o ./cycle_finder.bin

cycle_finder_test.bin: ./cycle_finder_test.c permutation_iterator mixed_radix
	gcc -I ./ -I ./permutation_iterator -I ./mixed_radix ./cycle_finder_test.c ./permutation_iterator/permutation_iterator.o ./mixed_radix/mixed_radix.o -o ./cycle_finder_test.bin

.PHONY: cayley

cayley:
	cd ./cayley; make

.PHONY: permutation_iterator

permutation_iterator:
	cd ./permutation_iterator; make

.PHONY: mixed_radix

mixed_radix:
	cd ./mixed_radix; make
