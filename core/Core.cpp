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
}

void arcade::Core::init(const std::string &argLib)
{
    this->_manager.loadArgumentLibrary(argLib);
    this->_manager.loadLibrairies("./lib");
    this->_display = this->_manager.getDisplay();
    this->_game = this->_manager.getMainMenu();
}

void arcade::Core::run()
{
    std::unique_ptr<ArcadeEvent> event;
    _display->init();
    _game->init();
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
        this->_game->destroy();
        return;
    }
    if (_game->getType() == LibraryType::MENU) {
        _game->onEvent(*event);
        return;
    }

    if (dynamic_cast<SwitchEvent *>(event.get())) {
        auto tmp = dynamic_cast<SwitchEvent *>(event.get());
        std::cout << *tmp << std::endl;
        if (tmp->getType() == api::event::SwitchEvent::DISPLAY) {
            this->_display->destroy();
            this->_manager.switchDisplay(tmp->getDirection());
            this->_display = this->_manager.getDisplay();
            this->_display->init();
        } else if (tmp->getType() == api::event::SwitchEvent::GAME) {
            this->_game->destroy();
            this->_manager.switchGame(tmp->getDirection());
            this->_game = this->_manager.getGame();
            this->_game->init();
        }
        return;
    }
    if (dynamic_cast<RestartEvent *>(event.get())) {
        _game->restart();
        return;
    }
    if (dynamic_cast<LaunchMenuEvent *>(event.get())) {
        _game->destroy();
        _display->reset();
        _game = _manager.getMainMenu();
        _game->init();
        return;
    }
    if (dynamic_cast<KeyEvent *>(event.get())) {
        auto tmp = dynamic_cast<KeyEvent *>(event.get());
        return;
    }
    _game->onEvent(*event);
}

void arcade::Core::stop()
{
    this->_manager.unloadAll();
}
