# .PHONY: all say_hello1 say_hello2 say_hello3 generate clean

# section1: say_hello1 say_hello2 # this ensures that all targets are excecuted.
# # say_hello is the function, called target. echo "Hello World" is a recipe. There are prerequisetes that can follow the function (none in this case). Combined this makes a rule.

# say_hello1:
# 	echo "Hello World" 

# # doing it this way will surpress the print out of recipe and display only its output. 
# say_hello2: 
# 	@echo "Hello World" 

# ----------------------------------------------------------------

# section2: say_hello2 say_hello3 generate edit

# say_hello3: # says hello
# 	@echo "Hello World"

# generate: # creates 10 files 
# 	@echo "Creating empty text files..."
# 	# touch file-{1..10}.txt

# clean: # removes the 10 files
# 	@echo "Cleaning up..."
# 	rm file-*.txt

# build: helper.c 
# 	gcc helper.c misc.c -o a.exe
# 	a.exe
# 	@rm *.exe *.txt

# ----------------------------------------------------------------

# section3: object edit run

# # this will create a target 
# object: misc.c helper.c
# 	@gcc -c misc.c helper.c

# edit: object
# 	@gcc misc.o helper.o -o a.exe

# run: edit 
# 	@./a.exe
# 	@rm a.exe *.o

# ----------------------------------------------------------------
# using objects as a variable 

# section4: compileandrun 

# objects = misc.c helper.c

# compileandrun: ${objects}
# 	@gcc ${objects} -o b.exe
# 	@./b.exe
# 	@rm b.exe *.o

# ----------------------------------------------------------------
# using implicit rule for updating .o files 

# section5: run2
# obj = misc.c helper.c
# misc.o : ${obj} # this is an implicit declaration - GNU know to use cc to compile the .c files to get .o files out
# helper.o : helper.c 
# run2: ${obj}
# 	@gcc ${obj} -o c.exe
# 	@./c.exe
# 	@rm c.exe *.o

# ----------------------------------------------------------------
# another way to use implicit rule for updating .o files. We can group targets rather than prerequisites
# gcc -c a.c b.c  ::: -c is a flag to create object files rather than an excecutable

.PHONY : clean
section6: run3
objcts = misc.c helper.c
output = misc.o helper.o
${output}: ${objcts} # this is an implicit declaration - GNU know to use cc to compile the .c files to get .o files out
	@gcc -c ${objcts}
run3: ${output}
	@gcc ${output} -o c.exe
	@./c.exe
clean: 	
	@rm c.exe *.o
