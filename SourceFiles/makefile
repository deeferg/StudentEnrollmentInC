CC = gcc
CC_FLAGS = -g -ansi -pedantic -Wall -w
FILES = main.c student.c course.c sorting.c
OUT_EXE = assignment1
build: $(FILES)
	$(CC) $(CC_FLAGS) -o $(OUT_EXE) $(FILES)
clean:
	rm -f *.o core *.exe *~
rebuild: clean build
