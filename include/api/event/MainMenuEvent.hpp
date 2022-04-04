/*
** EPITECH PROJECT, 2022
** MainMenuEvent.hpp
** File description:
** MainMenuEvent.hpp
*/

#ifndef ARCADE_MAINMENUEVENT_HPP
#define ARCADE_MAINMENUEVENT_HPP

#include "IEvent.hpp"

namespace arcade::api::event {
    /**
     * @brief Triggered from the main menu
     */
    class MainMenuEvent : public IEvent {
    public:
        /**
         * @brief Construct a new MainMenuEvent
         * @param gameIdx the game index
         * @param displayIdx the display index
         */
        explicit MainMenuEvent(int gameIdx, int displayIdx)
        {
            this->_gameIdx = gameIdx;
            this->_displayIdx = displayIdx;
        }

        /**
         * @brief Get the game index
         * @return the game index
         */
        int getGameIndex() const { return this->_gameIdx; }

        /**
         * @brief Get the display index
         * @return the display index
         */
        int getDisplayIndex() const { return this->_displayIdx; }

    private:
        int _gameIdx; /**< The game index */
        int _displayIdx; /**< The display index */
    };
}

#endif //ARCADE_MAINMENUEVENT_HPP
