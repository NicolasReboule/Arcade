##
## EPITECH PROJECT, 2022
## B-OOP-400-RUN-4-1-arcade-nicolas.reboule
## File description:
## Makefile
##

NCURSES_FLAGS = -lncurses

SDL2_FLAGS = -lSDL2

IFLAGS_API = -I ../include/api

SMFL_FLAGS = -lsfml-window -lsfml-graphics -lsfml-system -l sfml-audio

IFLAGS_NCURSES = -I ../include/ncurses/

IFLAGS_SDL2 = -I ../include/sdl2/ -I ../include/api -I ../include/api/event

IFLAGS_SFML = -I ../include/sfml/

NAME_NCURSES = arcade_ncurses.so

NAME_SDL2 = arcade_sdl2.so

NAME_SFML = arcade_sfml.so

SRC_SDL2 = $(wildcard sdl2/*.cpp)

SRC_NCURSES = $(wildcard ncurses/*.cpp)

SRC_SFML = $(wildcard sfml/*.cpp)

OBJ_NCURSES = $(SRC_NCURSES:.cpp $(IFLAGS_NCURSES)=.o)

OBJ_SDL2 = $(SRC_SDL2:.cpp $(IFLAGS_SDL2)=.o)

OBJ_SFML = $(SRC_SFML:.cpp $(IFLAGS_SFML)=.o)

OBJ_GRAPHICALS = $(OBJ_NCURSES) $(OBJ_SDL2) $(OBJ_SFML)

all:
	make -j$(PROC) compile

compile: $(OBJ_GRAPHICALS)
	g++ -shared -o $(NAME_NCURSES) -fPIC $(OBJ_NCURSES) $(IFLAGS_NCURSES) $(NCURSES_FLAGS) $(IFLAGS_API)
	g++ -shared -o $(NAME_SDL2) -fPIC $(OBJ_SDL2) $(IFLAGS_SDL2) $(SDL2_FLAGS)
	g++ -shared -o $(NAME_SFML) -fPIC $(OBJ_SFML) $(IFLAGS_SFML) $(SMFL_FLAGS)
	mkdir -p ../lib/
	mv $(NAME_NCURSES) $(NAME_SDL2) $(NAME_SFML)  ../lib/

clean:
	rm -f ncurses/*.o
	rm -f sdl2/*.o
	rm -f sfml/*.o

fclean: clean
	rm -rf ../lib/ $(NAME_NCURSES)
	rm -rf ../lib/ $(NAME_SDL2)
	rm -rf ../lib/ $(NAME_SFML)

re: fclean re
