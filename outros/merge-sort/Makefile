FLAGS := -g3 -fsanitize=address,undefined

all: merge_sort.o main

merge_sort.o: merge_sort.h merge_sort.c
	@gcc -c merge_sort.c -o merge_sort.o $(FLAGS)

main: main.c merge_sort.o
	@gcc -o main main.c merge_sort.o $(FLAGS)

clean:
	@if [ -f main ]; then rm main; fi
	@if [ -f merge_sort.o ]; then rm merge_sort.o; fi