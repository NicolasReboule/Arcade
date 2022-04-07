/*
** EPITECH PROJECT, 2022
** Constant.hpp
** File description:
** Constant.hpp
*/

#ifndef ARCADE_CONSTANT_HPP
#define ARCADE_CONSTANT_HPP

#define ARCADE_WIDTH (1280) /**< Default width of a window */
#define ARCADE_HEIGHT (720) /**< Default height of a window */
#define TTY_RATIO (16) /**< Ratio of the terminal */
#define RATIO_CENTER (TTY_RATIO / 2.0f) /**< Middle of the TTY_RATIO */

#include "api/renderer/Color.hpp"

namespace arcade::api {
    struct NColors {
        int idx = 0;
        ArcadeColor color;
    };

    static inline const NColors COLORS[] = {
        {1, ArcadeColor::Black},
        {2, ArcadeColor::White},
        {3, ArcadeColor::Red},
        {4, ArcadeColor::Green},
        {5, ArcadeColor::Blue},
        {6, ArcadeColor::Yellow},
        {7, ArcadeColor::Magenta},
        {8, ArcadeColor::Cyan}
    };
}

#endif //ARCADE_CONSTANT_HPP
