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
    class IArcadeException : public std::exception {
    public:
        /**
         * @brief Should always return a valid exception message to be displayed
         * @return the exception message
         */
        virtual const char *what() const noexcept override = 0;
    };

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
        std::string _msg;
    };

    /**
     * @brief Exception thrown when a library is not found
     */
    class LibraryNotFound : public ArcadeException {
    public:
        explicit LibraryNotFound(const std::string &msg) : ArcadeException(msg) {}
    };

    /**
     * @brief Exception thrown when a library is already loaded
     */
    class LibraryAlreadyLoaded : public ArcadeException {
    public:
        explicit LibraryAlreadyLoaded(const std::string &msg) : ArcadeException(msg) {}
    };

    /**
     * @brief Exception thrown when a library is not loaded
     */
    class LibraryNotLoaded : public ArcadeException {
    public:
        explicit LibraryNotLoaded(const std::string &msg) : ArcadeException(msg) {}
    };

    /**
     * @brief Exception thrown when the entrypoint of the library is not found
     */
    class LibraryEntryPointNotFound : public ArcadeException {
    public:
        explicit LibraryEntryPointNotFound(const std::string &msg) : ArcadeException(msg) {}
    };

    /**
     * @brief Exception thrown when the handle is invalid
     */
    class LibraryInvalidHandle : public ArcadeException {
    public:
        explicit LibraryInvalidHandle(const std::string &msg) : ArcadeException(msg) {}
    };

}

#endif //ARCADE_IARCADEEXCEPTION_HPP
