##
## EPITECH PROJECT, 2022
## B-OOP-400-RUN-4-1-arcade-nicolas.reboule
## File description:
## Makefile
##


CPP_FLAGS = -Wall -Wextra -std=c++20

PROC ?= 1

all: core graphicals games

core:
	make -C core

games:
	make -C games

graphicals:
	make -C graphicals

clean:
	make clean -C core
	make clean -C games
	make clean -C graphicals


fclean: clean
	make fclean -C core
	make fclean -C games
	make fclean -C graphicals
	rm -f ./arcade
	rm -rf $(LIB_DIR)

re: fclean all

api:
	make api -C doc

force_api:
	FORCE=1 make api -C doc

doc:
	make doc -C doc

copy_api:
	FORCE=1 make copy -C doc

.PHONY: all core games graphicals clean fclean doc re api force_api