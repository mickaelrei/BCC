FLAGS := -Wall -Wextra

all: main

main: main.cpp polynomial.hpp
	$(CXX) main.cpp -o main $(FLAGS)

clean:
	@if [ -f main ]; then rm main; fi