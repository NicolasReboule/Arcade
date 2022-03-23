/*
** EPITECH PROJECT, 2022
** LibraryEntryPointNotFound.hpp
** File description:
** LibraryEntryPointNotFound.hpp
*/

#ifndef ARCADE_LIBRARYENTRYPOINTNOTFOUND_HPP
#define ARCADE_LIBRARYENTRYPOINTNOTFOUND_HPP

#include "LibraryException.hpp"

namespace arcade::api::ex {
    /**
     * @brief Exception thrown when the entrypoint of the library is not found
     */
    class LibraryEntryPointNotFound : public LibraryException {
    public:
        explicit LibraryEntryPointNotFound(const std::string &msg) : LibraryException(msg) {}
    };
}

#endif //ARCADE_LIBRARYENTRYPOINTNOTFOUND_HPP
