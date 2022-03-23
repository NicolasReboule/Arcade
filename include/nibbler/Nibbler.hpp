/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "api/IGameModule.hpp"
namespace arcade::api {
    class Nibbler : public IGameModule
    {
        public:
            explicit Nibbler(const std::string &name);
            ~Nibbler();
            inline void init() override {};
            inline void destroy() override {};
            inline void update() override {};
            inline const std::string &getName() const override {return _name;};
            // inline IGameModule *getInstance() override {return NULL;};
            inline void onEvent(event::IEvent &event) override {};
            inline void render(IDisplayModule &display) override {};

        private:
        std::string _name;
    };
}

#endif /* !NIBBLER_HPP_ */
