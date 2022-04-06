/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "api/AbstractGameModule.hpp"

namespace arcade::api {
    class Nibbler : public AbstractGameModule {
    public:
        enum Direction {
            UP,
            DOWN,
            LEFT,
            RIGHT
        };
        explicit Nibbler();

        ~Nibbler();

        const std::string &getName() const override;

        LibraryType getType() const override;

        void init() override;

        void destroy() override;

        bool isRunning() override;

        static Nibbler *getInstance();

        void onEvent(event::IEvent &event) override;

        void render(IDisplayModule &display) override;

        void update(std::size_t tick) override;

        void restart() override;

    private:
        static std::unique_ptr<Nibbler> _instance;
        std::vector<std::unique_ptr<Sprite>> _gamesDrawables;
        std::size_t _time;
        Direction _direction;
    };
}

#endif /* !NIBBLER_HPP_ */
