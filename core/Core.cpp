/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Core
*/

#include "Core.hpp"
#include "Sdl2.hpp"
#include "IDisplayModule.hpp"

void arcade::Core::run()
{
    arcade::api::event::IEvent events;
    // arcade::DlLoader<arcade::api::IDisplayModule> display("./lib/arcade_sdl2.so");
    auto display = this->_manager.getDisplayLoader()->getInstance();
    display->init();
    while (display->isOpen()) {
        display->pollEvent(events);
        display->clear();
        display->display();
    }
    display->destroy();
}

void arcade::Core::setGame(const std::string &name)
{
    _manager.setGameLoader(name);
}

std::string arcade::Core::getGame(void)
{
    return _manager.getGameLoader()->getInstance()->getName();
}

void arcade::Core::setDisplay(const std::string &name)
{
    _manager.setDisplayLoader(name);
}
