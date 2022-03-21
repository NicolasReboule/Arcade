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
    // std::list<std::string> games;
    // std::list<std::string> displays;
    // games.push_back("./lib/arcade_nibbler.so");
    // arcade::Core core(games, displays);
    arcade::DlLoader<arcade::api::IGameModule> load("./lib/arcade_nibbler.so");
    return 0;
}