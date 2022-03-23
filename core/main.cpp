/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** main
*/

#include "core/Core.hpp"

int main(void)
{
    arcade::Core core;
    core.run();

    





    // core.setGame("j");
    // std::cout << core.getGame() << std::endl;
    // void *h =  dlopen("./lib/arcade_sdl2.so", RTLD_LAZY);
    // if (h == NULL)
    //     std::cout << dlerror() << std::endl;
    // else {
    //     std::shared_ptr<arcade::api::Sdl2>(*ok)() = (std::shared_ptr<arcade::api::Sdl2>(*)())dlsym(h, "_ZN6arcade3api4Sdl210entryPointEv");
    //     if (!ok)
    //         std::cout << dlerror() << std::endl;
    //     auto tmp = ok();
    //     dlclose(h);
    //     tmp->init();
    // }
    return 0;
}
