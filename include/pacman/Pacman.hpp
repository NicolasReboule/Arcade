/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "api/AGameModule.hpp"
namespace arcade::api {
    class Pacman : public AGameModule
    {
        public:
            explicit Pacman(const std::string &name);
            ~Pacman();
            inline void init() override {};
            inline void destroy() override {};
            inline void update() override {};
            inline void draw() override {};
        private:
    };
}

#endif /* !PACMAN_HPP_ */
