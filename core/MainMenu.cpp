/*
** EPITECH PROJECT, 2022
** MainMenu.cpp
** File description:
** MainMenu.cpp
*/

#include "core/MainMenu.hpp"

arcade::menu::MainMenu::MainMenu(Core *core) : api::AbstractGameModule("MainMenu")
{
    _core = core;
    _gameIdx = 0;
    _onDisplay = true;
    _current = nullptr;
}

LibraryType arcade::menu::MainMenu::getType() const
{
    return LibraryType::MENU;
}

void arcade::menu::MainMenu::init()
{
    _drawables.clear();
    Text text("allo", "walkthemoon.ttf", ArcadeColor::White);
    text.setPosition(256, 256);
    _drawables.push_back(std::make_unique<Text>(text));
    this->initGlobalMenu();
    this->initDisplays();
    this->initGames();
}

void arcade::menu::MainMenu::update(std::size_t tick)
{
    (void)tick;
}

void arcade::menu::MainMenu::onEvent(api::event::IEvent &event)
{
}

void arcade::menu::MainMenu::render(api::IDisplayModule &display)
{
    for (auto &item : _drawables)
        display.draw(*item);
    for (auto &item : _displayDrawables)
        display.draw(*item);
    for (auto &item : _gamesDrawables)
        display.draw(*item);
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
    this->destroy();
    this->init();
}

void arcade::menu::MainMenu::initGlobalMenu()
{
}

void arcade::menu::MainMenu::initDisplays()
{
}

void arcade::menu::MainMenu::initGames()
{
}

