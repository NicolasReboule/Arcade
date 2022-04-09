/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** main
*/

#include "core/Core.hpp"
#include <chrono>

void printUsage()
{
    std::cout << "Arcade usage:" << std::endl;
    std::cout << "\t./arcade to print this message" << std::endl;
    std::cout << "\t./arcade -h to print this message" << std::endl;
    std::cout << "\t./arcade [path to graphical library" << std::endl;
    std::cout << "\t\tExemple: ./arcade lib/arcade_sfml.so" << std::endl;
    std::cout << "\nKeybinds:" << std::endl;
    std::cout << "\tM to go to the menu" << std::endl;
    std::cout << "\tR to restart the game" << std::endl;
    std::cout << "\tEscape to quit the game" << std::endl;
    std::cout << "\tLeft and Right arrows to switch graphical library" << std::endl;
    std::cout << "\tUp and Down arrows to switch game" << std::endl;
    std::cout << "\tZ to go up" << std::endl;
    std::cout << "\tS to go down" << std::endl;
    std::cout << "\tQ to go to the left" << std::endl;
    std::cout << "\tD to go to the right" << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        printUsage();
        return 84;
    }
    std::string argPath(av[1]);
    if (argPath == "-h")
        printUsage();
    arcade::Core core;
    try {
        core.init(argPath);
    } catch (std::exception &e) {
        std::cout << "Core: Initialization" << std::endl;
        std::cerr << "Core: " << e.what() << std::endl;
        std::cout << "Core: Initialized" << std::endl;
        return 84;
    }
    try {
        std::cout << "Core: Running" << std::endl;
        core.run();
    } catch (std::exception &e) {
        std::cerr << "Core:" << e.what() << std::endl;
    }
    try {
        std::cout << "Core: Stopping" << std::endl;
        core.stop();
        std::cout << "Core: Stopped" << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
