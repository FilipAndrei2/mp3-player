CC = g++
FLAGS = -Wall -Wextra -g
INCLUDE_DIR = -I include/
LIB_DIR = -L lib/
LIBS = -lSDL2 -lSDL2main -lSDL2_image -lSDL2_mixer -lSDL2_ttf -limgui -lpython312
CPP_FILES = src/*.cpp

BUILD_DIR = bin
BUILD_NAME = debug

default: compile run

compile:
	$(CC) $(FLAGS) $(INCLUDE_DIR) $(LIB_DIR) $(CPP_FILES) -o $(BUILD_DIR)/$(BUILD_NAME) $(LIBS) 

run:
	./$(BUILD_DIR)/$(BUILD_NAME)