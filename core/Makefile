##
## EPITECH PROJECT, 2022
## B-OOP-400-RUN-4-1-arcade-nicolas.reboule
## File description:
## Makefile
##

NAME = arcade

IFLAGS_CORE = -I ../include/core/ -I ../include -I ../include/sdl2 -I ../include/ncurces -I ../include/api

SRC_CORE = $(wildcard ./*.cpp)

OBJ_CORE = $(SRC_CORE:.cpp $(IFLAGS_CORE)=.o)

CPP_FLAGS = -Wall -Wextra -std=c++20

PROC ?= 1

all:
	make -j$(PROC) compile

compile: $(OBJ_CORE)
	g++ -o $(NAME) $(OBJ_CORE) $(CPP_FLAGS) $(IFLAGS_CORE) -ldl
	mv $(NAME) ../

clean:
	rm -f ./*.o

fclean: clean
	rm -rf ../arcade

re: fclean all