/*
** EPITECH PROJECT, 2022
** LibraryException.hpp
** File description:
** LibraryException.hpp
*/

#ifndef ARCADE_LIBRARYEXCEPTION_HPP
#define ARCADE_LIBRARYEXCEPTION_HPP

#include "ArcadeException.hpp"

namespace arcade::api::ex {
    /**
     * @brief Exception thrown when the entrypoint of the library is not found
     */
    class LibraryException : public ArcadeException {
    public:
        explicit LibraryException(const std::string &msg) : ArcadeException(msg) {}
    };
}

#endif //ARCADE_LIBRARYEXCEPTION_HPP
