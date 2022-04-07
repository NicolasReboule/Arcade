/*
** EPITECH PROJECT, 2022
** ParserException.hpp
** File description:
** ParserException.hpp
*/

#ifndef ARCADE_PARSEREXCEPTION_HPP
#define ARCADE_PARSEREXCEPTION_HPP

#include "ArcadeException.hpp"

namespace arcade::api::ex {
    class ParserException : public ArcadeException {
    public:
        /**
         * @brief Exception thrown when the method draw of a base drawable is called
         */
        explicit ParserException(const std::string &message) : ArcadeException(message) {}
    };
}

#endif //ARCADE_PARSEREXCEPTION_HPP
