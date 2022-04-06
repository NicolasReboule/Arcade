##
## EPITECH PROJECT, 2022
## B-OOP-400-RUN-4-1-arcade-nicolas.reboule
## File description:
## Makefile
##

OBJ_GAMES = $(OBJ_NIBBLER) $(OBJ_PACMAN)

OBJ_PACMAN = $(SRC_PACMAN:.cpp=.o)

OBJ_NIBBLER = $(SRC_NIBBLER:.cpp=.o)

SRC_PACMAN = $(wildcard ./pacman/*.cpp)

SRC_NIBBLER = $(wildcard ./nibbler/*.cpp)

NAME_NIBBLER = arcade_nibbler.so

NAME_PACMAN = arcade_pacman.so

CPPFLAGS = -W -Wall -Wextra -std=c++20 -I ../include -fPIC

all:
	make -j$(PROC) compile

compile: $(OBJ_GAMES)
	g++ -shared -o $(NAME_PACMAN) $(CPPFLAGS) $(OBJ_PACMAN)
	g++ -shared -o $(NAME_NIBBLER) $(CPPFLAGS) $(OBJ_NIBBLER)
	mkdir -p ../lib/
	mv $(NAME_NIBBLER) ../lib/
	mv $(NAME_PACMAN) ../lib/

clean:
	rm -rf nibbler/*.o
	rm -rf pacman/*.o
	rm -rf ./*.o

fclean: clean
	rm -rf ../lib/$(NAME_NIBBLER)
	rm -rf ../lib/$(NAME_PACMAN)

re: fclean all
