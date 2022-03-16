##
## EPITECH PROJECT, 2022
## B-OOP-400-RUN-4-1-arcade-nicolas.reboule
## File description:
## Makefile
##


CPP_FLAGS = -Wall -Wextra -Werror -std=c++20

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

# doc:
# 	make -C doc

re: fclean all

.PHONY: all core games graphicals clean fclean doc re