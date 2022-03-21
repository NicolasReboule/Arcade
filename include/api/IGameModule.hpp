/*
** EPITECH PROJECT, 2022
** IGameModule.hpp
** File description:
** IGameModule.hpp
*/

#ifndef ARCADE_IGAMEMODULE_HPP
#define ARCADE_IGAMEMODULE_HPP

#include "library/ILibrary.hpp"
#include "IDisplayModule.hpp"
#include "event/IEvent.hpp"

namespace arcade::api {
    /**
     * @brief Interface for all the games
     */
    class IGameModule : library::ILibrary {
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
         * @brief Get the name of the library
         * @return the name of the library
         */
        const std::string &getName() const override = 0;

        /**
         * @brief Get the instance of the game
         * @return the instance of the game
         */
        IGameModule *getInstance() override = 0; //TODO: check if the polymorphism works like that

        /**
         * @brief Handle the event of the game
         * @see arcade::api::event::KeyEvent and arcade::api::event::MouseEvent
         * @return the event of the game
         */
        virtual void onEvent(event::IEvent &event) = 0;

        /**
         * Render the game
         * @param display used to render anything on the display @see IDisplayModule#draw
         */
        virtual void render(IDisplayModule &display) = 0;

        /**
         * @brief Destroy the game
         */
        virtual void destroy() = 0;
    };
}

#endif //ARCADE_IGAMEMODULE_HPP
