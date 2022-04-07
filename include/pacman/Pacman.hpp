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
        enum class MapType {
            NONE,
            BORDER,
            PAC,
            GHOST,
            FOOD,
            PORTAL
        };

        enum Direction {
            UP,
            DOWN,
            LEFT,
            RIGHT,
            NOPE
        };

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

        void initMap();
        void initBorder(float, float);
        void initPac(float, float);
        void initGhost(float, float);
        void initFood(float, float);
        void initPortal(float, float);

    private:
        static std::unique_ptr<Pacman> _instance;
        std::vector<std::unique_ptr<Sprite>> _gamesDrawables;
        Sprite _pac;
        std::size_t _time;
        Direction _direction;
        std::unordered_map<char, MapType> _map;

    };
}

#endif /* !PACMAN_HPP_ */
