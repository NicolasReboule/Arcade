/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** main
*/

#include "DlLoader.hpp"
#include "Core.hpp"

int main(void)
{
    std::list<std::string> games;
    std::list<std::string> displays;
    games.push_back("./lib/arcade_nibbler.so");
    games.push_back("./lib/arcade_pacman.so");
    // displays.push_back("./lib/arcade_ncurses.so");
    // displays.push_back("./lib/arcade_sfml.so");
    arcade::Core core(games, displays);
    core.setGame("Nibbler");
    std::cout << core.getGame() << std::endl;
    core.setGame("Pacman");
    std::cout << core.getGame() << std::endl;
    core.setGame("j");
    std::cout << core.getGame() << std::endl;
    return 0;
}