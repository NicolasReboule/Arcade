/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Core
*/

#include "core/Core.hpp"
#include "api/IDisplayModule.hpp"

arcade::Core::Core() {
    this->isRunning = true; //TODO: remove this 🤷‍
}

void arcade::Core::init() {

}

void arcade::Core::run()
{
    arcade::api::event::IEvent event;
    auto display = this->_manager.getDisplay();
    auto game = this->_manager.getGame();
    display->init();
    while (display->isOpen()) {
        if (display->pollEvent(event)) {
            game->onEvent(event);
        }
        display->clear();
        display->display();
    }
    display->destroy();
}
