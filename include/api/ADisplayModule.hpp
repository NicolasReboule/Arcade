/*
** EPITECH PROJECT, 2022
** ADisplayModule.hpp
** File description:
** ADisplayModule
*/

#ifndef ADISPLAYMODULE_HPP_
#define ADISPLAYMODULE_HPP_

#include "IGameModule.hpp"
#include "IDisplayModule.hpp"
#include <list>
#include <iostream>
#include <memory>

namespace arcade::api
{
    class ADisplayModule : public IDisplayModule {
        public:
            explicit ADisplayModule(const std::string &name, IGameModule &game);
            ADisplayModule(const std::string &name);
            ~ADisplayModule() override = default;
            inline std::string getName() const override {return _name;};
        protected:
            std::string _name;
            std::shared_ptr<IGameModule> _game;
    };
}

#endif /* !ADISPLAYMODULE_HPP_ */
