/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Nibbler
*/

#include "nibbler/Nibbler.hpp"
#include "api/event/SwitchEvent.hpp"

std::unique_ptr<arcade::api::Nibbler> arcade::api::Nibbler::_instance;

arcade::api::Nibbler::Nibbler()
{
    _name = "Nibbler";
}

void arcade::api::Nibbler::update(std::size_t tick)
{
}

arcade::api::Nibbler::~Nibbler()
{
    std::cout << "Nibbler : bye" << std::endl;
}

void arcade::api::Nibbler::restart()
{

}

extern "C" arcade::api::Nibbler *entryPoint()
{
    return arcade::api::Nibbler::getInstance();
}

arcade::api::Nibbler *arcade::api::Nibbler::getInstance()
{
    if (_instance == nullptr)
        _instance = std::make_unique<Nibbler>();
    return _instance.get();
}

void arcade::api::Nibbler::onEvent(event::IEvent &event)
{
    if (dynamic_cast<event::SwitchEvent *>(&event)) {
        std::cout << "ojhgf" << std::endl;
    }
}