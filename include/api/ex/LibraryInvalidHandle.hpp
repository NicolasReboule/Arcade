/*
** EPITECH PROJECT, 2022
** LibraryInvalidHandle.hpp
** File description:
** LibraryInvalidHandle.hpp
*/

#ifndef ARCADE_LIBRARYINVALIDHANDLE_HPP
#define ARCADE_LIBRARYINVALIDHANDLE_HPP

#include "LibraryException.hpp"

namespace arcade::api::ex {
    /**
    * @brief Exception thrown when the handle is invalid
    */
    class LibraryInvalidHandle : public LibraryException {
    public:
        explicit LibraryInvalidHandle(const std::string &msg) : LibraryException(msg) {}
    };
}

#endif //ARCADE_LIBRARYINVALIDHANDLE_HPP
