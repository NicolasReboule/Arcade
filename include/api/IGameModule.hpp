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
#include <vector>

namespace arcade::api {
    /**
     * @brief Interface for all the games
     */
    class IGameModule : public library::ILibrary {
    public:
        virtual ~IGameModule() = default;

        /**
         * @brief Initialize the game
         */
        virtual void init() = 0;

        /**
         * @brief Update the game
         * @param tick actual timestamp in nanoseconds
         * @see arcade::api::utils::Time#getNanosecondsTime
         */
        virtual void update(std::size_t tick) = 0;

        /**
         * @brief Get the name of the library
         * @return the name of the library
         */
        const std::string &getName() const override = 0;

        /**
         * @brief Get the type of the library
         * @attention Should always return LibraryType::GAME
         * @return the type of the library
         */
        LibraryType getType() const override = 0;

        /**
         * @brief Handle the event of the game
         * @see api/event/Events.hpp
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

        /**
         * @brief Restart the game
         */
        virtual void restart() = 0;

        /**
         * @brief Check if the game is running
         * @return if the game is running
         */
        virtual bool isRunning() = 0;

        /**
         * @brief Get the score of the game
         * @return the score of the game
         */
        virtual std::size_t &getScore() = 0;

    };
}

#endif //ARCADE_IGAMEMODULE_HPP
