/*
** EPITECH PROJECT, 2022
** LibraryAlreadyLoaded.hpp
** File description:
** LibraryAlreadyLoaded.hpp
*/

#ifndef ARCADE_LIBRARYALREADYLOADED_HPP
#define ARCADE_LIBRARYALREADYLOADED_HPP

#include "LibraryException.hpp"

namespace arcade::api::ex {
    /**
     * @brief Exception thrown when a library is already loaded
     */
    class LibraryAlreadyLoaded : public LibraryException {
    public:
        explicit LibraryAlreadyLoaded(const std::string &msg) : LibraryException(msg) {}
    };
}

#endif //ARCADE_LIBRARYALREADYLOADED_HPP
