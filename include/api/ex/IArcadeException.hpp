/*
** EPITECH PROJECT, 2022
** IArcadeException.hpp
** File description:
** IArcadeException.hpp
*/

#ifndef ARCADE_IARCADEEXCEPTION_HPP
#define ARCADE_IARCADEEXCEPTION_HPP

#include <iostream>

namespace arcade::api::ex {
    /**
     * @brief Interface of arcade exception
     */
    class IArcadeException : public std::exception {
    public:
        /**
         * @brief Should always return a valid exception message to be displayed
         * @return the exception message
         */
        virtual const char *what() const noexcept override = 0;
    };

}

#endif //ARCADE_IARCADEEXCEPTION_HPP
