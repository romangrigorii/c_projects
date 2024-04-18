CC=gcc
CFLAGS=-Wall -g

MODULE = gravitational.o
TARGET = gravitational.so 
INPUTS = gravitational.c
BUILD = ../../../build

# $(TARGET): $(MODULE)
# 	$(CC) $(CFLAGS) -shared $^ -o $@

$(MODULE): *.c
	$(CC) $(CFLAGS) -fpic -c $^ -o $@
	
clean: 
	rm *.o