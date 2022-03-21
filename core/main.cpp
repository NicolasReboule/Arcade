/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** main
*/

#include "DlLoader.hpp"
#include "Core.hpp"
#include "Sdl2.hpp"

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
    void *h =  dlopen("./lib/arcade_sdl2.so", RTLD_LAZY);
    void *h =  dlopen("./lib/arcade_ncurses.so", RTLD_LAZY);
    std::shared_ptr<arcade::api::Curses> temp;
    if (h == NULL)
        std::cout << dlerror() << std::endl;
    else {
        std::shared_ptr<arcade::api::Sdl2>(*ok)() = (std::shared_ptr<arcade::api::Sdl2>(*)())dlsym(h, "_ZN6arcade3api4Sdl210entryPointEv");
        if (!ok)
            std::cout << dlerror() << std::endl;
        auto tmp = ok();
        temp = ok();
        dlclose(h);
        tmp->init();
    }
    temp->init();

    // test.init();
    return 0;
}
