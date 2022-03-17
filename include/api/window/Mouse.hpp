/*
** EPITECH PROJECT, 2022
** Mouse.hpp
** File description:
** Mouse.hpp
*/

#ifndef ARCADE_MOUSE_HPP
#define ARCADE_MOUSE_HPP

namespace arcade::api::window {
    enum MouseButton {
        LEFT,
        RIGHT,
        MIDDLE
    };
    enum MouseAction {
        PRESSED,
        RELEASED
    };
}

#endif //ARCADE_MOUSE_HPP
