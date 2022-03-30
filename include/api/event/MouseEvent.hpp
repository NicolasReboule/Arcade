/*
** EPITECH PROJECT, 2022
** MouseEvent.hpp
** File description:
** MouseEvent.hpp
*/

#ifndef ARCADE_MOUSEEVENT_HPP
#define ARCADE_MOUSEEVENT_HPP

#include "IEvent.hpp"
#include "api/window/Mouse.hpp"
#include "api/utils/Vector.hpp"

namespace arcade::api::event {
    /**
     * @brief Triggered when mouse is pressed/released
     */
    class MouseEvent : public IEvent {
    public:
        /**
         * @brief Constructor of MouseEvent
         * @param action the mouse action
         * @param button the mouse button
         * @param pos the position of the mouse
         */
        explicit MouseEvent(window::MouseAction action, window::MouseButton button, Vector2i pos)
        {
            this->_action = action;
            this->_button = button;
            this->_pos = pos;
        }

        /**
         * @brief Get the coordinate
         * @return the coordinate @see Vector2<int>
         */
        inline Vector2i getCoordinate() const
        {
            return this->_pos;
        }

        /**
         * @brief Get the button used
         * @return the mouse button
         */
        inline window::MouseButton getButton() const
        {
            return this->_button;
        }

        /**
         * @brief Get the action
         * @return the mouse action
         */
        inline window::MouseAction getAction() const
        {
            return this->_action;
        }

        /**
         * Get if the mouse key is pressed
         * @return if the mouse key is pressed
         */
        inline bool isPressed() const
        {
            return this->_action == window::MouseAction::PRESSED;
        }

        /**
         * Get if the mouse key is released
         * @return if the mouse key is released
         */
        inline bool isReleased() const
        {
            return this->_action == window::MouseAction::RELEASED;
        }

    protected:
        Vector2i _pos /**< The coordinate */;
        window::MouseButton _button; /**< The mouse button */
        window::MouseAction _action; /**< The mouse action */
    };
}

inline std::ostream &operator<<(std::ostream &os, const arcade::api::event::MouseEvent &event)
{
    os << "MouseEvent: " << event.getCoordinate() << " " << event.getButton() << " " << event.getAction();
    return os;
}

#endif //ARCADE_MOUSEEVENT_HPP
