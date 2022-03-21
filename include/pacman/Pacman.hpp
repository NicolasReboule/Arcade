/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "api/IGameModule.hpp"
namespace arcade::api {
    class Pacman : public IGameModule
    {
        public:
            explicit Pacman(const std::string &name);
            ~Pacman();
            inline void init() override {};
            inline void destroy() override {};
            inline void update() override {};

        private:
            std::string _name;
    };
}

#endif /* !PACMAN_HPP_ */
