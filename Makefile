##
## EPITECH PROJECT, 2022
## B-OOP-400-RUN-4-1-arcade-nicolas.reboule
## File description:
## Makefile
##

NAME = arcade

NAME_NCURSES = arcade_ncurses.so

NAME_SDL2 = arcade_sdl2.so

NAME_SFML = arcade_sfml.so

NAME_NIBBLER = arcade_nibbler.so

NAME_PACMAN = arcade_pacman.so

SRC_CORE = $(wildcard core/*.cpp)

SRC_SDL2 = $(wildcard graphicals/sdl2/*.cpp)

SRC_NCURSES = $(wildcard graphicals/ncurses/*.cpp)

SRC_SFML = $(wildcard graphicals/smfl/*.cpp)

SRC_PACMAN = $(wildcard games/pacman/*.cpp)

SRC_NIBBLER = $(wildcard games/nibbler/*.cpp)

OBJ_CORE = $(SRC_CORE:.cpp $(IFLAGS_CORE)=.o)

OBJ_GRAPHICALS = $(OBJ_NCURSES) $(OBJ_SDL2) $(OBJ_SFML)

OBJ_NCURSES = $(SRC_NCURSES:.cpp $(IFLAGS_NCURSES)=.o)

OBJ_SDL2 = $(SRC_SDL2:.cpp $(IFLAGS_SDL2)=.o)

OBJ_SFML = $(SRC_SFML:.cpp $(IFLAGS_SFML)=.o)

OBJ_GAMES = $(OBJ_NIBBLER) $(OBJ_PACMAN)

OBJ_PACMAN = $(SRC_PACMAN:.cpp $(IFLAGS_PACMAN)=.o)

OBJ_NIBBLER = $(SRC_NIBBLER:.cpp $(IFLAGS_NIBBLER)=.o)

IFLAGS_CORE = -I include/core/

IFLAGS_NCURSES = -I include/ncurses/

IFLAGS_SDL2 = -I include/sdl2/

IFLAGS_SFML = -I include/sfml/

IFLAGS_PACMAN = -I include/pacman

IFLAGS_NIBBLER = -I include/nibbler

CPP_FLAGS = -Wall -Wextra -Werror -std=c++20

NCURSES_FLAGS = -lncurses

SDL2_FLAGS = -lSDL2

SMFL_FLAGS = -lsfml-window -lsfml-graphics -lsfml-system -l sfml-audio

all: core graphicals games

core: $(OBJ_CORE)
	g++ -o $(NAME) $(OBJ_CORE) $(CPP_FLAGS) $(IFLAGS_CORE) -ldl

graphicals: $(OBJ_GRAPHICALS)
	g++ -shared -o $(NAME_NCURSES) -fPIC $(OBJ_NCURSES) $(IFLAGS_NCURSES) $(NCURSES_FLAGS)
	g++ -shared -o $(NAME_SDL2) -fPIC $(OBJ_SDL2) $(IFLAGS_SDL2) $(SDL2_FLAGS)
	g++ -shared -o $(NAME_SFML) -fPIC $(OBJ_SFML) $(IFLAGS_SFML) $(SMFL_FLAGS)
	mv $(NAME_NCURSES) $(NAME_SDL2) $(NAME_SFML)  lib/

games: $(OBJ_GAMES)
	g++ -shared -o $(NAME_PACMAN) -fPIC $(OBJ_PACMAN) $(IFLAGS_PACMAN)
	g++ -shared -o $(NAME_NIBBLER) -fPIC $(OBJ_NIBBLER) $(IFLAGS_NIBBLER)
	mv $(NAME_NIBBLER) $(NAME_PACMAN) lib/

clean:
	rm -f core/*.o
	rm -f graphicals/ncurses/*.o
	rm -f graphicals/sdl2/*.o
	rm -f graphicals/sfml/*.o
	rm -f games/nibbler/*.o
	rm -f games/pacman/*.o

fclean: clean
	rm -f lib/*.so
	rm -f *.so
	rm -f $(NAME)

re: fclean all
