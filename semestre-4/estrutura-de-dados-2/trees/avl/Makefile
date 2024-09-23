FLAGS := -Wall -Wextra -g3 -fsanitize=address,undefined

all: avl_tree.o main

avl_tree.o: avl_tree.h avl_tree.c
	gcc -c avl_tree.c -o avl_tree.o -lm $(FLAGS)

main: main.c avl_tree.o
	gcc main.c avl_tree.o -o main -lm $(FLAGS)

clean:
	@if [ -f main ]; then rm main; fi
	@if [ -f avl_tree.o ]; then rm avl_tree.o; fi