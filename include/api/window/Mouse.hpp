/*
** EPITECH PROJECT, 2022
** Mouse.hpp
** File description:
** Mouse.hpp
*/

#ifndef ARCADE_MOUSE_HPP
#define ARCADE_MOUSE_HPP

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

#endif //ARCADE_MOUSE_HPP
