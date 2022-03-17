/*
** EPITECH PROJECT, 2022
** IDisplayModule.hpp
** File description:
** IDisplayModule.hpp
*/

#ifndef ARCADE_IDISPLAYMODULE_HPP
#define ARCADE_IDISPLAYMODULE_HPP

#include "IGameModule.hpp"
#include <iostream>

namespace arcade::api {
    class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;

        /**
         * @brief Init the display module
         */
        virtual void init() = 0;

        /**
         * @brief Destroy the display module
         */
        virtual void destroy() = 0;

        /**
         * @brief Run the game
         */
        virtual void run() = 0;

        /**
         * @brief Display the game
         */
        virtual void display() = 0;

        /**
         * @brief Update the display
         */
        virtual void update() = 0;

        /**
         * @brief Check if the window is open(
         * @return if the window is open
         */
        virtual bool isOpen() const = 0;

        /**
         * @brief Clear the window
         */
        virtual void clear() = 0;

        /**
         * @brief Return the instance name
         */
        virtual std::string getName() const = 0;
    };
}

#endif //ARCADE_IDISPLAYMODULE_HPP
