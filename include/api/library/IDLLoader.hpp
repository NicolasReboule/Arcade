/*
** EPITECH PROJECT, 2022
** IDLLoader.hpp
** File description:
** IDLLoader.hpp
*/

#ifndef ARCADE_IDLLOADER_HPP
#define ARCADE_IDLLOADER_HPP

#include "api/ex/Exceptions.hpp"
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
         * @param path the path to the library
         * @throws arcade::api::ex::LibraryNotFound
         */
        virtual void load(const std::string &path) = 0;

        /**
         * @brief Unload the library
         * Should call @code dlclose @endcode
         * Could throw @see arcade::api::ex::LibraryInvalidHandle
         */
        virtual void unload() = 0;

        /**
         * Load the instance of the generic type T
         * @tparam T the type of the instance
         * @throws arcade::api::ex::LibraryNotLoaded
         * @throws arcade::api::ex::LibraryEntryPointNotFound
         * @attention Should use the define @code ILibrary#ENTRY_POINT_NAME @endcode
         */
        virtual void loadInstance() = 0;

        /**
         * @brief Get the instance of the library
         * Call this only if the library is loaded and loadInstance has been called
         * @tparam T the type of the instance
         * @return the instance of T
         */
        virtual T *operator->() const = 0;

        /**
         * @brief Get the instance of the library
         * Call this only if the library is loaded and loadInstance has been called
         * @tparam T the type of the instance
         * @return the instance of T
         */
        virtual T *operator*() const = 0;

        /**
         * @brief Get the instance of the library
         * Call this only if the library is loaded and loadInstance has been called
         * @tparam T the type of the instance
         * @return the instance of T
         */
        virtual T *getInstance() const = 0;

        /**
         * @brief Get the path of the library
         * @return the path of the library
         */
        virtual const std::string &getPath() const = 0;
    };
}

#endif //ARCADE_IDLLOADER_HPP
