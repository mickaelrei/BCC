CFLAGS = -lglfw -lGL -lstdc++ -Wall

INCLUDE = ./glad/include

SOURCE = main.cpp \
		./glad/src/glad.c

TARGET_DIR = bin

TARGET = main

all:
	if [ ! -d $(TARGET_DIR) ]; then mkdir $(TARGET_DIR); fi
	$(CXX) -I$(INCLUDE) $(SOURCE) -o $(TARGET_DIR)/$(TARGET) $(CFLAGS)

run:
	./$(TARGET_DIR)/$(TARGET)

clean:
	rm $(TARGET_DIR)/*