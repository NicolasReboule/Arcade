/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "api/AGameModule.hpp"
namespace arcade::api {
    class Nibbler : public AGameModule
    {
        public:
            explicit Nibbler(const std::string &name);
            ~Nibbler();
            inline void init() override {};
            inline void destroy() override {};
            inline void update() override {};
            inline void draw() override {};
        private:
    };
}

#endif /* !NIBBLER_HPP_ */
