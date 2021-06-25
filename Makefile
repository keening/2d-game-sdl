OBJS =	src/main.cpp src/display.cpp src/application.cpp src/sprite.cpp src/player.cpp

CC = g++

COMPILER_FLAGS = -Wall

LINKER_FLAGS = -lSDL2 -lSDL2_image

OBJ_NAME = game

all : $(OBJS) 
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
