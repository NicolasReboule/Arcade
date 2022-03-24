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
            explicit Pacman();
            ~Pacman();
            inline void init() override {};
            inline void destroy() override {};
            inline void update() override {};
            inline const std::string &getName() const override {return _name;};
            inline LibraryType getType() const { return GAME; }
            static Pacman *getInstance();
            inline void onEvent(event::IEvent &event) override {};
            inline void render(IDisplayModule &display) override {};

        private:
        static std::unique_ptr<Pacman> _instance;
        std::string _name;
    };
}

#endif /* !PACMAN_HPP_ */
