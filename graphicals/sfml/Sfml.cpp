/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** sfml
*/

#include "sfml/Sfml.hpp"
#include <unistd.h>


std::unique_ptr<arcade::api::Sfml> arcade::api::Sfml::_instance;


arcade::api::Sfml::Sfml()
{
    _name = "SFML";
}

void arcade::api::Sfml::init()
{
    sf::Window _window(sf::VideoMode(800, 600), "Arcade Menu");
    _window.setFramerateLimit(60);
    _isOpen = true;
}

extern "C" arcade::api::Sfml *entryPoint(void)
{
    return arcade::api::Sfml::getInstance();
}

arcade::api::Sfml *arcade::api::Sfml::getInstance()
{
    if (_instance == nullptr)
        _instance = std::make_unique<Sfml>();
    return _instance.get();
}

void arcade::api::Sfml::destroy()
{
    _window->close();
}

void arcade::api::Sfml::display()
{
}

void arcade::api::Sfml::update()
{
}