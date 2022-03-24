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
    _window.create(sf::VideoMode(800, 600), "Arcade Menu");
    _window.setFramerateLimit(60);
    _isOpen = true;
}

void arcade::api::Sfml::clear()
{
    _window.clear();
    _window.display();
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
    _window.close();
}

void arcade::api::Sfml::display()
{
}

void arcade::api::Sfml::update()
{
}

bool arcade::api::Sfml::pollEvent(event::IEvent &event)
{
    sf::Event sfEvent;
    while (_window.pollEvent(sfEvent)) {
        if (sfEvent.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            _isOpen = false;
        }
        if (sfEvent.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            event = event::SwitchEvent(event::SwitchEvent::GAME, event::SwitchEvent::NEXT);
        }
        if (sfEvent.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            event = event::SwitchEvent(event::SwitchEvent::GAME, event::SwitchEvent::PREV);
        }
        if (sfEvent.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            event = event::SwitchEvent(event::SwitchEvent::DISPLAY, event::SwitchEvent::NEXT);
        }
        if (sfEvent.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            event = event::SwitchEvent(event::SwitchEvent::DISPLAY, event::SwitchEvent::PREV);
        }
    }
    return false;
}
