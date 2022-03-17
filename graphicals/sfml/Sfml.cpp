/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** sfml
*/

#include "Sfml.hpp"
#include <unistd.h>

extern "C"
{
    SFML::SFML(const std::string &name) : _name(name)
    {
        // init();
    }

    SFML::~SFML()
    {
        // stop();
    }

    SFML *entryPoint(void)
    {
        SFML *module = new SFML("SFML");
        printf("SFML entryPoint\n");
        return module;
    }
}