/*
** EPITECH PROJECT, 2022
** AMouseEvent.hpp
** File description:
** AMouseEvent.hpp
*/

#ifndef ARCADE_AMOUSEEVENT_HPP
#define ARCADE_AMOUSEEVENT_HPP

#include "IEvent.hpp"
#include "api/window/Mouse.hpp"
#include "api/Vector.hpp"

namespace arcade::api::event {
    /**
     * @brief Triggered when mouse is pressed/released
     */
    class AMouseEvent : public IEvent {
    public:
        AMouseEvent(window::MouseAction type, window::MouseButton button, Vector<int> pos);

        /**
         * @brief Get the coordinate
         * @return
         */
        virtual Vector<int> getCoordinate() const = 0;

        /**
         * @brief Get the button used
         * @return the mouse button
         */
        virtual window::MouseButton getButton() const = 0;

        /**
         * @brief Get the action
         * @return the mouse action
         */
        virtual window::MouseAction getAction() const = 0;

    protected:
        int _x; /**< The x coordinate */
        int _y; /**< The y coordinate */
        window::MouseButton _button; /**< The mouse button */
        window::MouseAction _action; /**< The mouse action */
    };
}

#endif //ARCADE_AMOUSEEVENT_HPP
