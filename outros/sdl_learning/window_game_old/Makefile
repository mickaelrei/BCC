FILES := application.cpp \
		 player.cpp \
		 collision.cpp \
		 main.cpp

OBJ_NAME := main

wbuild:
	g++ -I C:\SDL2\include -L C:\SDL2\lib $(FILES) -o $(OBJ_NAME) -lmingw32 -lSDL2main -lSDL2

build:
	g++ $(FILES) -o $(OBJ_NAME) -lSDL2main -lSDL2

run:
	./$(OBJ_NAME)