/*
** EPITECH PROJECT, 2022
** AGameModule.hpp
** File description:
** AGameModule
*/

#ifndef AGAMEMODULE_HPP_
#define AGAMEMODULE_HPP_

#include "IGameModule.hpp"
#include <list>
#include <iostream>
#include <memory>

namespace arcade::api
{
    class AGameModule : public IGameModule {
        public:
            explicit AGameModule(const std::string &name) : _name(name) {};
            ~AGameModule() = default;
            virtual void init() = 0;
            virtual void destroy() = 0;
            virtual void update() = 0;
            virtual void draw() = 0;
            inline std::string getName() const override {return _name;};
        protected:
            std::string _name;
    };
}

#endif /* !AGAMEMODULE_HPP_ */
