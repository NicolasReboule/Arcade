/*
** EPITECH PROJECT, 2022
** Mouse.hpp
** File description:
** Mouse.hpp
*/

#ifndef ARCADE_MOUSE_HPP
#define ARCADE_MOUSE_HPP

#include <iostream>

namespace arcade::api::window {
    /**
     * @brief The mouse button @see arcade::api::event::MouseEvent
     */
    enum MouseButton {
        LEFT,
        RIGHT,
        MIDDLE
    };

    /**
     * @brief The mouse action @see arcade::api::event::MouseEvent
     */
    enum MouseAction {
        PRESSED,
        RELEASED
    };
}

using MouseButton = arcade::api::window::MouseButton; /**< typedef because it's too long */
using MouseAction = arcade::api::window::MouseAction; /**< typedef because it's too long */

inline std::ostream &operator<<(std::ostream &os, const MouseButton &button)
{
    os << "MouseButton: ";
    switch (button) {
        case MouseButton::LEFT:
            os << "LEFT";
            break;
        case MouseButton::RIGHT:
            os << "RIGHT";
            break;
        case MouseButton::MIDDLE:
            os << "MIDDLE";
            break;
    }
    return os;
}

inline std::ostream &operator<<(std::ostream &os, const MouseAction &action)
{
    os << "MouseAction: ";
    switch (action) {
        case MouseAction::PRESSED:
            os << "PRESSED";
            break;
        case MouseAction::RELEASED:
            os << "RELEASED";
            break;
    }
    return os;
}

#endif //ARCADE_MOUSE_HPP
