/*
** EPITECH PROJECT, 2022
** LibraryNotLoaded.hpp
** File description:
** LibraryNotLoaded.hpp
*/

#ifndef ARCADE_LIBRARYNOTLOADED_HPP
#define ARCADE_LIBRARYNOTLOADED_HPP

#include "LibraryException.hpp"

namespace arcade::api::ex {
    /**
     * @brief Exception thrown when a library is not loaded
     */
    class LibraryNotLoaded : public LibraryException {
    public:
        explicit LibraryNotLoaded(const std::string &msg) : LibraryException(msg) {}
    };

}

#endif //ARCADE_LIBRARYNOTLOADED_HPP
