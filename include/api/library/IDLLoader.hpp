/*
** EPITECH PROJECT, 2022
** IDLLoader.hpp
** File description:
** IDLLoader.hpp
*/

#ifndef ARCADE_IDLLOADER_HPP
#define ARCADE_IDLLOADER_HPP

#include "api/ex/IArcadeException.hpp"
#include <string>

namespace arcade::api::library {
    /**
     * @brief Interface for the library loader
     * @tparam T the instance type
     */
    template <typename T>
    class IDLLoader {
    public:
        virtual ~IDLLoader() = default;

        /**
         * @brief Load a library
         * The handle will be stored in the class
         * @param the path to the library
         * @throws arcade::api::ex::LibraryNotFound
         */
        virtual void load(std::string &path) = 0;

        /**
         * @brief Unload the library
         * Should call @see dlclose
         * Could throw @see arcade::api::ex::LibraryInvalidHandle
         */
        virtual void unload() = 0;

        /**
         * Load the instance of the generic type T
         * @tparam T the type of the instance
         * @throws arcade::api::ex::LibraryNotLoaded
         * @throws arcade::api::ex::LibraryEntryPointNotFound
         */
        virtual void loadInstance() const = 0;

        /**
         * @brief Get the instance of the library
         * Call this only if the library is loaded and loadInstance has been called
         * @tparam T the type of the instance
         * @return the instance of T
         */
        virtual T *operator->() const = 0;

        /**
         * @brief Get the path of the library
         * @return the path of the library
         */
        virtual const std::string &getPath() const = 0;
    };
}

#endif //ARCADE_IDLLOADER_HPP
