OBJS =	source/main.cpp source/display.cpp source/application.cpp source/sprite.cpp source/player.cpp

CC = g++

COMPILER_FLAGS = -Wall

LINKER_FLAGS = -lSDL2 -lSDL2_image

OBJ_NAME = game

all : $(OBJS) 
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
