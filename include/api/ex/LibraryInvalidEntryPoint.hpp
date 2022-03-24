/*
** EPITECH PROJECT, 2022
** LibraryInvalidEntryPoint.cpp
** File description:
** LibraryInvalidEntryPoint.cpp
*/

#include "LibraryException.hpp"

namespace arcade::api::ex {
    /**
     * @brief Exception thrown when the entrypoint return the bad instance type
     */
    class LibraryInvalidEntryPoint : public LibraryException {
    public:
        explicit LibraryInvalidEntryPoint(const std::string &msg) : LibraryException(msg) {}
    };
}