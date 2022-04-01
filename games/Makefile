##
## EPITECH PROJECT, 2022
## B-OOP-400-RUN-4-1-arcade-nicolas.reboule
## File description:
## Makefile
##

OBJ_GAMES = $(OBJ_NIBBLER) $(OBJ_PACMAN) $(OBJ_MENU)

OBJ_PACMAN = $(SRC_PACMAN:.cpp $(IFLAGS_PACMAN)=.o)

OBJ_NIBBLER = $(SRC_NIBBLER:.cpp $(IFLAGS_NIBBLER)=.o)

OBJ_MENU = $(SRC_MENU:.cpp $(IFLAGS_MENU)=.o)

IFLAGS_PACMAN = -I ../include/pacman -I ../include

IFLAGS_NIBBLER = -I ../include/nibbler -I ../include

IFLAGS_MENU = -I ../include/menu -I ../include

SRC_PACMAN = $(wildcard ./pacman/*.cpp)

SRC_NIBBLER = $(wildcard ./nibbler/*.cpp)

SRC_MENU = $(wildcard ./menu/*.cpp)

NAME_NIBBLER = arcade_nibbler.so

NAME_PACMAN = arcade_pacman.so

NAME_MENU = arcade_menu.so

all:
	make -j$(PROC) compile

compile: $(OBJ_GAMES)
	g++ -shared -o $(NAME_PACMAN) -fPIC $(OBJ_PACMAN) $(IFLAGS_PACMAN)
	g++ -shared -o $(NAME_NIBBLER) -fPIC $(OBJ_NIBBLER) $(IFLAGS_NIBBLER)
	g++ -shared -o $(NAME_MENU) -fPIC $(OBJ_MENU) $(IFLAGS_MENU)
	mkdir -p ../lib/
	mv $(NAME_NIBBLER) ../lib/
	mv $(NAME_PACMAN) ../lib/
	mv $(NAME_MENU) ../lib/

clean:
	rm -rf nibbler/*.o
	rm -rf pacman/*.o
	rm -rf menu/*.o
	rm -rf ./*.o

fclean: clean
	rm -rf ../lib/$(NAME_NIBBLER)
	rm -rf ../lib/$(NAME_PACMAN)
	rm -rf ../lib/$(NAME_MENU)

re: fclean re
