# Set project directory one level above of Makefile directory. $(CURDIR) is a GNU make variable containing the path to the current working directory
PHYDIR := src/lib/physics
NUMDIR := src/lib/numeric
LINKINGFILES := $(NUMDIR)/randgen.o src/main.c $(PHYDIR)/gravitational.o

CC=gcc
CFLAGS=-Wall -g

build/simulation: $(LINKINGFILES)	
	@$(CC) $^ -o build/simulation 

# src/main.o: src/main.c
# 	@$(CC) $(CFLAGS) -c $^ -o $@

$(PHYDIR): # This will call make in all of the directories. 
	$(MAKE) --directory=$@

$(NUMDIR): # This will call make in all of the directories. 
	$(MAKE) --directory=$@

clean: $(NUMDIR)
	rm src/*.o simulation*