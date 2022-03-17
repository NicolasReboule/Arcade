/*
** EPITECH PROJECT, 2022
** IEventHandler.hpp
** File description:
** IEventHandler.hpp
*/

#ifndef ARCADE_IEVENTHANDLER_HPP
#define ARCADE_IEVENTHANDLER_HPP

#include "api/event/MouseEvent.hpp"
#include "api/event/KeyEvent.hpp"

namespace arcade::api::event {
    /**
     * @brief Interface for handling all events, need to be registered to the api
     */
    class IEventHandler {
    public:
        IEventHandler() = default;
        ~IEventHandler() = default;

        /**
         * Called when a mouse event is triggered
         * @param event the MouseEvent
         */
        virtual void onMouseEvent(MouseEvent &event) = 0;

        /**
         * Called when a key event is triggered
         * @param event the KeyEvent
         */
        virtual void onKeyEvent(KeyEvent &event) = 0;
    };
}

#endif //ARCADE_IEVENTHANDLER_HPP
