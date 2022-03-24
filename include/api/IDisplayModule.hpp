/*
** EPITECH PROJECT, 2022
** IDisplayModule.hpp
** File description:
** IDisplayModule.hpp
*/

#ifndef ARCADE_IDISPLAYMODULE_HPP
#define ARCADE_IDISPLAYMODULE_HPP

#include "event/IEvent.hpp"
#include "library/ILibrary.hpp"
#include <iostream>

namespace arcade::api {
    /**
     * @brief Interface for all the display
     */
    class IDisplayModule : public library::ILibrary {
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
         * @brief Display the game
         */
        virtual void display() = 0;

        /**
         * @brief Check if an event is available and pop it from the event list TODO: potential event list, for now only one event
         * @param event The event will be stored in it, if available
         * @return if an event is available
         */
        virtual bool pollEvent(event::IEvent &event) = 0;

        /**
         * Get the name of the display (for example: "SFML")
         * @return the name of the display
         */
        const std::string &getName() const override = 0;

        /**
         * @brief Get the type of the library
         * @attention Should always return LibraryType::DISPLAY
         * @return the type of the library
         */
        LibraryType getType() const override = 0;

        /**
         * @brief Update the display
         */
        virtual void update() = 0;

        /**
         * @brief Check if the system is open
         * @return if the system is open
         */
        virtual bool isOpen() const = 0;

        /**
         * @brief Clear the system, should always clear the screen to black
         */
        virtual void clear() = 0;
    };
}

#endif //ARCADE_IDISPLAYMODULE_HPP
