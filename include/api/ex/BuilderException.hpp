/*
** EPITECH PROJECT, 2022
** BuilderException.hpp
** File description:
** BuilderException.hpp
*/

#ifndef ARCADE_BUILDEREXCEPTION_HPP
#define ARCADE_BUILDEREXCEPTION_HPP

#include "ArcadeException.hpp"

namespace arcade::api::ex {
    /**
     * @brief Exception thrown when some value are missing in the build method
     */
    class BuilderException : public ArcadeException {
    public:
        explicit BuilderException(const std::string &msg) : ArcadeException(msg) {}
    };
}


#endif //ARCADE_BUILDEREXCEPTION_HPP
