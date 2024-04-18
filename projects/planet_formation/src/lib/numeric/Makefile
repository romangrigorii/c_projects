CC=gcc
CFLAGS=-Wall -g
BUILD = ../../../build
MODULE = randgen.o
TARGET = randgen.so 
INPUTS = randgen.c

# $(TARGET): $(MODULE)
# 	$(CC) $(CFLAGS) -shared $^ -o $@

$(MODULE): *.c
	$(CC) $(CFLAGS) -fpic -c $^ -o $@
	
clean: 
	rm *.o