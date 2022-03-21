/*
** EPITECH PROJECT, 2022
** ILibrary.hpp
** File description:
** ILibrary.hpp
*/

#ifndef ARCADE_ILIBRARY_HPP
#define ARCADE_ILIBRARY_HPP

#include <string>
#include <memory>

namespace arcade::api::library {
    /**
     * @brief Interface for all the library
     */
    class ILibrary {
    public:
        /**
         * @brief Destructor
         * Should destroy the instance of the library if not using unique_ptr
         */
        virtual ~ILibrary() = default;

        /**
         * @brief Get the name of the library, use this to display it in the menu
         * @return the name of the library
         */
        virtual const std::string &getName() const = 0;

        /**
         * @brief Get the instance of the library, aka the entrypoint of the library
         * @attention This should be used like this @code extern "C" arcade::api::library::ILibrary *getInstance() @endcode
         * @attention Use this as a singleton ?
         * @return the instance of the library
         */
        virtual ILibrary *getInstance() = 0;
    };
}

#endif //ARCADE_ILIBRARY_HPP
