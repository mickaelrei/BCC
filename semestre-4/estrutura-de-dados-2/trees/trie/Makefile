FLAGS := -Wall -Wextra -g3 -fsanitize=address,undefined

all: trie_tree.o main

trie_tree.o: trie_tree.h trie_tree.c
	gcc -c trie_tree.c -o trie_tree.o -lm $(FLAGS)

main: main.c trie_tree.o
	gcc main.c trie_tree.o -o main -lm $(FLAGS)

clean:
	@if [ -f main ]; then rm main; fi
	@if [ -f trie_tree.o ]; then rm trie_tree.o; fi