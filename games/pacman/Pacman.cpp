/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Pacman
*/

#include "pacman/Pacman.hpp"

std::unique_ptr<arcade::api::Pacman> arcade::api::Pacman::_instance;

void arcade::api::Pacman::update(std::size_t tick)
{
}

void arcade::api::Pacman::restart()
{

}

arcade::api::Pacman::Pacman()
{
    _name = "Pacman";
}

arcade::api::Pacman::~Pacman()
{
    std::cout << "Pacman : bye" << std::endl;
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