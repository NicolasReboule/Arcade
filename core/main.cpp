/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** main
*/

#include "core/Core.hpp"
#include <chrono>

void update(std::size_t tick)
{
    static std::size_t next = 0;

    std::cout << tick << "\n" << next << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    auto time = std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1);
    std::cout << time << std::endl;
    std::string argPath(av[1]);
    arcade::Core core;
    try {
        core.init(argPath);
    } catch (std::exception &e) {
        std::cerr << "fbour salocin: " << e.what() << std::endl;
        return 84;
    }
    try {
        std::cout << "wtff" << std::endl;
        core.run();
    } catch (std::exception &e) {
        std::cerr << "fbour hugo & chatdo:" << e.what() << std::endl;
    }
    try {
        core.stop();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
