all: mixed_radix_test.bin

mixed_radix_test.bin: ./mixed_radix_test.c ./mixed_radix.h mixed_radix.o
	gcc -I ./ ./mixed_radix_test.c ./mixed_radix.o -o ./mixed_radix_test.bin

mixed_radix.o: ./mixed_radix.h ./mixed_radix.c
	gcc -c ./mixed_radix.c
