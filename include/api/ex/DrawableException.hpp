/*
** EPITECH PROJECT, 2022
** DrawableException.hpp
** File description:
** DrawableException.hpp
*/

#ifndef ARCADE_DRAWABLEEXCEPTION_HPP
#define ARCADE_DRAWABLEEXCEPTION_HPP

#include "ArcadeException.hpp"

namespace arcade::api::ex {
    /**
     * @brief Exception thrown when the method draw of a base drawable is called
     */
    class DrawableException : public ArcadeException {
    public:
        explicit DrawableException(const std::string &msg) : ArcadeException(msg) {}
    };
}


#endif //ARCADE_DRAWABLEEXCEPTION_HPP
