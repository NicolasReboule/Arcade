/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "api/AbstractGameModule.hpp"

namespace arcade::api {
    class Pacman : public AbstractGameModule {
    public:
        explicit Pacman();

        ~Pacman();

        bool isRunning() override;

        void init() override;

        void update(std::size_t tick) override;

        void onEvent(event::IEvent &event) override;

        void render(IDisplayModule &display) override;

        static Pacman *getInstance();

        void destroy() override;

        void restart() override;

    private:
        static std::unique_ptr<Pacman> _instance;
    };
}

#endif /* !PACMAN_HPP_ */
