/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

    extern "C"
    {
        arcade::api::Nibbler::Nibbler(const std::string &name)
        {
            _name = name;
            std::cout << "Nibbler : hey" << std::endl;
        }

        arcade::api::Nibbler::~Nibbler()
        {
            std::cout << "Nibbler : bye" << std::endl;
        }

        std::shared_ptr<arcade::api::Nibbler> entryPoint(void)
        {
            std::cout << "Nibbler entryPoint" << std::endl;
            std::shared_ptr<arcade::api::Nibbler> module = std::make_shared<arcade::api::Nibbler>("Nibbler");
            return module;
        }
    }