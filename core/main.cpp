/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** main
*/

#include "DlLoader.hpp"
#include "Core.hpp"
#include "Ncurses.hpp"

int main(void)
{
    // std::list<std::string> games;
    // std::list<std::string> displays;
    // games.push_back("./lib/arcade_nibbler.so");
    // arcade::Core core(games, displays);
    // core.setGame("Nibbler");
    // std::cout << core.getGame() << std::endl;
    // core.setGame("Pacman");
    // std::cout << core.getGame() << std::endl;
    // core.setGame("j");
    // std::cout << core.getGame() << std::endl;
    void *h =  dlopen("./lib/arcade_ncurses.so", RTLD_LAZY);
    if (h == NULL)
        std::cout << dlerror() << std::endl;
    else {
        std::shared_ptr<arcade::api::Curses>(*ok)() = (std::shared_ptr<arcade::api::Curses>(*)())dlsym(h, "_ZN6arcade3api6Curses10entryPointEv");
        if (!ok)
            std::cout << dlerror() << std::endl;
        ok();
        dlclose(h);
    }
    return 0;
}
