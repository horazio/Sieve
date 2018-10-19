all : driver.o sieve.o
	gcc driver.o sieve.o -lm

driver.o : driver.c
	gcc -c driver.c

sieve.o : sieve.c sieve.h
	gcc -c sieve.c -lm

run:
	./a.out
