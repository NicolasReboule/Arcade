/*
** EPITECH PROJECT, 2022
** IGameModule.hpp
** File description:
** IGameModule.hpp
*/

#ifndef ARCADE_IGAMEMODULE_HPP
#define ARCADE_IGAMEMODULE_HPP

#include <string>

namespace arcade::api {
    class IGameModule {
    public:
        virtual ~IGameModule() = default;

        /**
         * @brief Initialize the game
         */
        virtual void init() = 0;

        /**
         * @brief Update the game
         */
        virtual void update() = 0;

        /**
         * @brief Render the game
         */
        virtual void draw() = 0;

        /**
         * @brief Destroy the game
         */
        virtual void destroy() = 0;

        /**
         * @brief Return the instance name
         */
        virtual std::string getName() const = 0;
    };
}

#endif //ARCADE_IGAMEMODULE_HPP
