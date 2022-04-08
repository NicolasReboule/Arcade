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
        enum class MapType {
            NONE,
            BORDER,
            WALL,
            SNAKE,
            FOOD,
        };

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

        void moveSnake();

        void addTail();

        bool isTail();

        void initMap();
        void initDie();
        void initBorder(float, float);
        void initSnake(float, float);
        void initWall(float, float);
        void initFood(float, float);

    private:
        static std::unique_ptr<Nibbler> _instance;
        std::vector<std::unique_ptr<Sprite>> _gamesDrawables;
        std::vector<std::unique_ptr<Sprite>> _snakeDrawables;
        std::vector<std::unique_ptr<renderer::AbstractDrawable>> _dieDrawables;
        std::vector<std::vector<MapType>> _parsed_map;
        bool _isAlive;
        Vector2u _map_size;
        Sprite _food;
        Random _rand;
        std::size_t _time;
        Direction _direction;
        std::unordered_map<char, MapType> _map;

    };
}

#endif /* !NIBBLER_HPP_ */
