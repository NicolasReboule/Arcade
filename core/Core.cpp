/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Core
*/

#include "core/Core.hpp"
#include "core/MainMenu.hpp"

arcade::Core::Core() : AbstractCore()
{
    this->_menu = nullptr;
}

void arcade::Core::init(const std::string &argLib)
{
    this->_manager.loadArgumentLibrary(argLib);
    this->_manager.loadLibrairies(this->_libDirPath);
    _menu = new menu::MainMenu(this);
    this->_display = this->_manager.getDisplay();
    _game = _menu;
    _display->init();
    _game->init();
}

void arcade::Core::run()
{
    std::unique_ptr<ArcadeEvent> event;
    while (_display->isOpen()) {
        if (_display->pollEvent(event))
            this->handleEvent(event);
        if (!_display->isOpen())
            break;
        _display->clear();
        _game->update(Time::getNanosecondsTime());
        _game->render(*_display);
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
        _game = _menu;
        _game->init();
        return;
    }
    _game->onEvent(*event);
}

void arcade::Core::stop()
{
    this->_manager.unloadAll();
    delete _menu;
}

void arcade::Core::update()
{
    _game->destroy();
    _display->destroy();
    _game = _manager.getGame();
    _display = _manager.getDisplay();
    _display->init();
    _game->init();
}

arcade::api::library::IDLManager &arcade::Core::getDLManager()
{
    return _manager;
}

void arcade::Core::setUsername(const std::string &username)
{
    _username = username;
}

const std::string &arcade::Core::getUsername() const
{
    return _username;
}
