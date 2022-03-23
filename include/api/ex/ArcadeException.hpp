/*
** EPITECH PROJECT, 2022
** ArcadeException.hpp
** File description:
** ArcadeException.hpp
*/

#ifndef ARCADE_ARCADEEXCEPTION_HPP
#define ARCADE_ARCADEEXCEPTION_HPP

#include "IArcadeException.hpp"

namespace arcade::api::ex {
    /**
     * @brief Arcade exception should herit of this class
     */
    class ArcadeException : public IArcadeException {
    public:
        /**
         * @brief Construct a new ArcadeException object
         * @param message the exception message
         */
        explicit ArcadeException(const std::string &msg) : _msg(msg) {}

        /**
         * @brief Should always return a valid exception message to be displayed
         * @return the exception message
         */
        const char *what() const noexcept override { return _msg.c_str(); }

    private:
        std::string _msg; /**< The exception message */
    };
}

#endif //ARCADE_ARCADEEXCEPTION_HPP
