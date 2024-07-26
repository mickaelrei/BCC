FLAGS := -Wall -Wextra

all: binary_tree.o main

binary_tree.o: binary_tree.h binary_tree.c
	gcc -c binary_tree.c -o binary_tree.o -lm $(FLAGS)

main: main.c binary_tree.o
	gcc main.c binary_tree.o -o main -lm $(FLAGS)

clean:
	@if [ -f main ]; then rm main; fi
	@if [ -f binary_tree.o ]; then rm binary_tree.o; fi