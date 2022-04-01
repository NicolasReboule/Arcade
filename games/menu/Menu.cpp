/*
** EPITECH PROJECT, 2022
** Menu.cpp
** File description:
** Menu.cpp
*/

#include "menu/Menu.hpp"
#include "api/event/SwitchEvent.hpp"

std::unique_ptr<arcade::api::Menu> arcade::api::Menu::_instance;

arcade::api::Menu::Menu() : AbstractGameModule("Menu")
{
    _name = "Menu";
}

arcade::api::Menu::~Menu()
{
    std::cout << "Menu : bye" << std::endl;
}

extern "C" arcade::api::Menu *entryPoint()
{
    return arcade::api::Menu::getInstance();
}

arcade::api::Menu *arcade::api::Menu::getInstance()
{
    if (_instance == nullptr)
        _instance = std::make_unique<Menu>();
    return _instance.get();
}

bool arcade::api::Menu::isRunning()
{
    return false;
}

void arcade::api::Menu::init()
{
}

void arcade::api::Menu::update(std::size_t tick)
{
}

void arcade::api::Menu::onEvent(arcade::api::event::IEvent &event)
{
}

void arcade::api::Menu::render(arcade::api::IDisplayModule &display)
{
}

void arcade::api::Menu::destroy()
{
}

void arcade::api::Menu::restart()
{
}
