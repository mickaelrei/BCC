CC := g++

FILES := src/application/application.cpp \
		 src/player/player.cpp \
		 src/collision/collision.cpp \
		 main.cpp

WFLAGS := -lmingw32

FLAGS := -lSDL2main \
		 -lSDL2 \

OBJ_NAME := main

wbuild:
	$(CC) -I C:\SDL2\include -L C:\SDL2\lib $(FILES) -o $(OBJ_NAME) $(WFLAGS) $(FLAGS)

build:
	$(CC) $(FILES) -o $(OBJ_NAME) $(FLAGS)

run:
	./$(OBJ_NAME)