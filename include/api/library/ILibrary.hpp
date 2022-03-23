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

#define ENTRY_POINT_NAME "entryPoint"

namespace arcade::api::library {
    /**
     * @brief Interface for all the library
     *
     * @attention You should add a static method **getInstance** to your library,
     * this method need to be static and return a pointer to your library
     *
     * Your entryPoint method name should be the same as the define **ENTRY_POINT_NAME**
     *
     * Basic implementation of ILibrary
     * @code
     * // Library.hpp
     * class Library : public ILibrary {
     * public:
     *      Library();
     *
     *      const std::string &getName() const override;
     * private:
     *      static std::unique_ptr<Library> _instance;
     *      std::string _name;
     * }
     *
     * //Library.cpp
     * std::unique_ptr<Library> Library::_instance;
     *
     * Library::Library()
     * {
     *      this->_name = "Library";
     * }
     *
     * const std::string &Library::getName() const
     * {
     *     return this->_name;
     * }
     *
     * Library::Library *getInstance()
     * {
     *      if (_instance == nullptr)
     *          _instance = std::make_unique<Library>();
     *      return _instance.get();
     * }
     *
     * extern "C" Library::entryPoint() //This should be the same name as the define *ENTRY_POINT_NAME*
     * {
     *      return Library::getInstance();
     * }
     * @endcode
     */
    class ILibrary {
    public:
        /**
         * @brief Default constructor
         * @attention Don't remove this, this is used to not interfer with deleted copy constructor
         */
        ILibrary() = default;

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
         * @brief Remove the copy constructor
         */
        ILibrary(const ILibrary &) = delete;

        /**
         * @Brief Remove the copy constructor
         * @return nothing
         */
        ILibrary& operator=(const ILibrary &) = delete;
    };
}

#endif //ARCADE_ILIBRARY_HPP
