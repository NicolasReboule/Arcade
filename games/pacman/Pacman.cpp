/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Pacman
*/

#include "pacman/Pacman.hpp"

std::unique_ptr<arcade::api::Pacman> arcade::api::Pacman::_instance;

void arcade::api::Pacman::restart()
{

}

arcade::api::Pacman::Pacman(): AbstractGameModule("Pacman")
{
}

arcade::api::Pacman::~Pacman()
{
    std::cout << "Pacman : bye" << std::endl;
}

bool arcade::api::Pacman::isRunning()
{
    return AbstractGameModule::isRunning();
}

void arcade::api::Pacman::init()
{
}

void arcade::api::Pacman::update(std::size_t tick)
{
    (void)tick;
}

void arcade::api::Pacman::onEvent(arcade::api::event::IEvent &event)
{
    (void)event;
}

void arcade::api::Pacman::render(arcade::api::IDisplayModule &display)
{
    (void)display;
}

void arcade::api::Pacman::destroy()
{
}

extern "C" arcade::api::Pacman *entryPoint()
{
    return arcade::api::Pacman::getInstance();
}

arcade::api::Pacman *arcade::api::Pacman::getInstance()
{
    if (_instance == nullptr)
        _instance = std::make_unique<Pacman>();
    return _instance.get();
}
