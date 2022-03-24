/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Nibbler
*/

#include "nibbler/Nibbler.hpp"

std::unique_ptr<arcade::api::Nibbler> arcade::api::Nibbler::_instance;

arcade::api::Nibbler::Nibbler()
{
    _name = "Nibbler";
}

arcade::api::Nibbler::~Nibbler()
{
    std::cout << "Nibbler : bye" << std::endl;
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