/*
** EPITECH PROJECT, 2022
** MainMenu.cpp
** File description:
** MainMenu.cpp
*/

#include "core/MainMenu.hpp"

arcade::menu::MainMenu::MainMenu(Core *core) : api::AbstractGameModule("MainMenu"),
                                               _username("Username: ", "walkthemoon.ttf", ArcadeColor::Blue)
{
    _core = core;
    _gameIdx = 0;
    _displayIdx = 0;
    _hasUsername = false;
    _displaySelected = false;
    _gameSelected = false;
    _onDisplay = true;
    _current = nullptr;
}

LibraryType arcade::menu::MainMenu::getType() const
{
    return LibraryType::MENU;
}

void arcade::menu::MainMenu::init()
{
    this->_gameIdx = _core->getDLManager().getGameIndex();
    this->_displayIdx = _core->getDLManager().getDisplayIndex();
    this->_onDisplay = true;
    this->_current = nullptr;
    _displaySelected = false;
    _gameSelected = false;
    this->_drawables.clear();
    this->initGlobalMenu();
    this->initDisplays();
    this->initGames();
}

void arcade::menu::MainMenu::update(std::size_t tick)
{
    (void)tick;
    this->_username.setText("Username: " + this->_core->getUsername());
}

void arcade::menu::MainMenu::onEvent(api::event::IEvent &event)
{
    if (!_hasUsername) {
        try {
            auto key = dynamic_cast<const KeyEvent &>(event);
            std::cout << key << "\n";
            if (key.isPressed() && key.getKey() == KeyCode::Enter)
                _hasUsername = true;
            else if(key.isPressed()) {
                if (key.getKey() == KeyCode::Backspace)
                    _core->setUsername(_core->getUsername().substr(0, _core->getUsername().size() - 1));
                else if (key.getKey() == KeyCode::Space)
                    _core->setUsername(_core->getUsername() + " ");
                else
                    _core->setUsername(_core->getUsername() + *key.getKey());
            }
        } catch (std::bad_cast &e) {}
        try {
            auto key = dynamic_cast<const RestartEvent &>(event);
            _core->setUsername(_core->getUsername() + "R");
        } catch (std::bad_cast &e) {}
        try {
            auto key = dynamic_cast<const LaunchMenuEvent &>(event);
            _core->setUsername(_core->getUsername() + "M");
        } catch (std::bad_cast &e) {}
    } else if (!_gameSelected) {
        try {
            auto key = dynamic_cast<const SwitchEvent &>(event);
            if (key.getType() == SwitchType::GAME &&
                key.getDirection() == SwitchDirection::PREV) {
                _gamesDrawables[_gameIdx]->setColor(ArcadeColor::Blue);
                _gameIdx = (_gameIdx + 1 < _core->getDLManager().gameCount()) ?
                           _gameIdx + 1 : 0;
                _gamesDrawables[_gameIdx]->setColor(ArcadeColor::Cyan);
                _core->getDLManager().switchGame(SwitchDirection::PREV);
            } else if (key.getType() == SwitchType::GAME &&
                       key.getDirection() == SwitchDirection::NEXT) {
                _gamesDrawables[_gameIdx]->setColor(ArcadeColor::Blue);
                _gameIdx = ((int) _gameIdx - 1 >= 0) ?
                           _gameIdx - 1 : _core->getDLManager().gameCount() - 1;
                _gamesDrawables[_gameIdx]->setColor(ArcadeColor::Cyan);
                _core->getDLManager().switchGame(SwitchDirection::NEXT);
            }
        } catch (std::bad_cast &e) {}
        try {
            auto key = dynamic_cast<const KeyEvent &>(event);
            if (key.isPressed() && key.getKey() == KeyCode::Enter)
                _gameSelected = true;
        } catch (std::bad_cast &e) {}
    } else {
        try {
            auto key = dynamic_cast<const SwitchEvent &>(event);
            if (key.getType() == SwitchType::GAME &&
                key.getDirection() == SwitchDirection::PREV) {
                _displayDrawables[_displayIdx]->setColor(ArcadeColor::Blue);
                _displayIdx = (_displayIdx + 1 < _core->getDLManager().displayCount()) ?
                           _displayIdx + 1 : 0;
                _displayDrawables[_displayIdx]->setColor(ArcadeColor::Cyan);
                _core->getDLManager().switchDisplay(SwitchDirection::NEXT);
            } else if (key.getType() == SwitchType::GAME &&
                       key.getDirection() == SwitchDirection::NEXT) {
                _displayDrawables[_displayIdx]->setColor(ArcadeColor::Blue);
                _displayIdx = ((int) _displayIdx - 1 >= 0) ?
                           _displayIdx - 1 : _core->getDLManager().displayCount() - 1;
                _displayDrawables[_displayIdx]->setColor(ArcadeColor::Cyan);
                _core->getDLManager().switchDisplay(SwitchDirection::PREV);
            }
        } catch (std::bad_cast &e) {}
        try {
            auto key = dynamic_cast<const KeyEvent &>(event);
            if (key.isPressed() && key.getKey() == KeyCode::Enter) {
                _displaySelected = true;
                _core->update();
            }
        } catch (std::bad_cast &e) {}
    }
}

void arcade::menu::MainMenu::render(api::IDisplayModule &display)
{
    if (!_hasUsername) {
        for (auto &item: _drawables)
            display.draw(*item);
        display.draw(_username);
    }
    else if (_gameSelected) {
        for (auto &item: _displayDrawables)
            display.draw(*item);
        display.draw(_username);
    }
    else {
        for (auto &item: _gamesDrawables)
            display.draw(*item);
        display.draw(_username);
    }
//    for (auto &item : _highscoresDrawables)
//        display.draw(*item);
}

void arcade::menu::MainMenu::destroy()
{
    _displayDrawables.clear();
    _gamesDrawables.clear();
    _highscoresDrawables.clear();
}

void arcade::menu::MainMenu::restart()
{
    _gameIdx = 0;
    _onDisplay = true;
    this->destroy();
    this->init();
}

void arcade::menu::MainMenu::initGlobalMenu()
{
    _username.setPosition(ARCADE_WIDTH/2.0 + 200, ARCADE_HEIGHT/2.0);
}

void arcade::menu::MainMenu::initDisplays()
{
    float y = 200;
    auto displays = _core->getDLManager().getDisplays();
    for (auto &item : displays) {
        Text text(item, "walkthemoon.ttf", ArcadeColor::Blue);
        text.setPosition(400, y);
        y += 200;
        _displayDrawables.push_back(std::make_unique<Text>(text));
    }
    _displayDrawables[_displayIdx]->setColor(ArcadeColor::Cyan);
}

void arcade::menu::MainMenu::initGames()
{
    float y = 200;
    auto games = _core->getDLManager().getGames();
    for (auto &item : games) {
        Text text(item, "walkthemoon.ttf", ArcadeColor::Blue);
        text.setPosition(200, y);
        y += 200;
        _gamesDrawables.push_back(std::make_unique<Text>(text));
    }
    _gamesDrawables[_gameIdx]->setColor(ArcadeColor::Cyan);
}

