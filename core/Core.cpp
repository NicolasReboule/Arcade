/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Core
*/

#include "core/Core.hpp"
#include "api/IDisplayModule.hpp"

arcade::Core::Core() : AbstractCore()
{
    this->_isRunning = true; //TODO: remove this 🤷‍
}

void arcade::Core::init(const std::string &argLib)
{
    this->_manager.loadArgumentLibrary(argLib);
    this->_manager.loadLibrairies("./lib");
    this->_display = this->_manager.getDisplay();
}

void arcade::Core::run()
{
    std::unique_ptr<ArcadeEvent> event;
    //auto game = this->_manager.getGame();
    _display->init();
    while (_display->isOpen()) {
        if (_display->pollEvent(event)) {
            this->handleEvent(event);
        }
        _display->clear();
        _display->display();
    }
    this->_display->destroy();
}

void arcade::Core::handleEvent(const std::unique_ptr<ArcadeEvent> &event)
{
    if (dynamic_cast<CloseEvent *>(event.get())) {
        this->_display->destroy();
    }
    if (dynamic_cast<SwitchEvent *>(event.get())) {
        auto tmp = dynamic_cast<SwitchEvent *>(event.get());
        std::cout << *tmp << std::endl;
        if (tmp->getType() == api::event::SwitchEvent::DISPLAY) {
            this->_display->destroy();
            this->_manager.switchDisplay(tmp->getDirection());
            this->_display = this->_manager.getDisplay();
            this->_display->init();
        }
    }
}

void arcade::Core::stop()
{
    this->_manager.unloadAll();
}
