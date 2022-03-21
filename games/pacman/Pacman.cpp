/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Pacman
*/

#include "Pacman.hpp"

    extern "C"
    {
        arcade::api::Pacman::Pacman(const std::string &name) : AGameModule(name)
        {
            std::cout << "Pacman : hey" << std::endl;
        }

        arcade::api::Pacman::~Pacman()
        {
            std::cout << "Pacman : bye" << std::endl;
        }

        std::shared_ptr<arcade::api::Pacman> entryPoint(void)
        {
            std::cout << "Pacman entryPoint" << std::endl;
            // std::shared_ptr<arcade::api::Pacman> module = std::make_shared<arcade::api::Pacman>("Pacman");
            return nullptr;
        }
    }