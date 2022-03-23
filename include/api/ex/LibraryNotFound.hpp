/*
** EPITECH PROJECT, 2022
** LibraryNotFound.hpp
** File description:
** LibraryNotFound.hpp
*/

#ifndef ARCADE_LIBRARYNOTFOUND_HPP
#define ARCADE_LIBRARYNOTFOUND_HPP

#include "ArcadeException.hpp"

namespace arcade::api::ex {
    /**
     * @brief Exception thrown when a library is not found
     */
    class LibraryNotFound : public LibraryException {
    public:
        explicit LibraryNotFound(const std::string &msg) : LibraryException(msg) {}
    };
}

#endif //ARCADE_LIBRARYNOTFOUND_HPP
