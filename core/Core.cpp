/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Core
*/

#include "Core.hpp"

void arcade::Core::setGame(const std::string &name)
{
    _manager.setGameLoader(name);
}

std::string arcade::Core::getGame(void)
{
    return _manager.getGameLoader()->getInstance()->getName();
}

