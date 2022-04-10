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
#include "api/utils/NonCopyable.hpp"

#define ENTRY_POINT_NAME "entryPoint"

namespace arcade::api::library {
    /**
     * @brief Interface for all the library
     *
     * @attention You should add a static method **getInstance** to your library,
     * this method need to be static and return a pointer to your library
     *
     * Your entryPoint method name should be the same as the define **ENTRY_POINT_NAME**
     * @see ENTRY_POINT_NAME
     *
     * Basic implementation of ILibrary
     * @code
     * // Library.hpp
     * class Library : public arcade::api::library::ILibrary {
     * public:
     *      Library();
     *      ~Library();
     *
     *      const std::string &getName() const override;
     * private:
     *      static std::unique_ptr<Library> _instance;
     *      //or use a pointer to the Library
     *      //static Library *_instance;
     *      std::string _name;
     * }
     *
     * //Library.cpp
     * std::unique_ptr<Library> Library::_instance; //or use a pointer to the Library
     * // Library *Library::_instance = nullptr;
     *
     * Library::Library()
     * {
     *      this->_name = "Library";
     * }
     *
     * Library::~Library()
     * {
     *      delete _instance; //only when using pointer to library
     * }
     *
     * const std::string &Library::getName() const
     * {
     *     return this->_name;
     * }
     *
     * LibraryType Library::getType()
     * {
     *      return LibraryType::GAME; //or LibraryType::DISPLAY
     * }
     *
     * Library::Library *getInstance()
     * {
     *      // or using library pointer
     *      // if (_instance == nullptr)
     *      //     _instance = new Library();
     *      // return _instance;
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
    class ILibrary : public utils::NonCopyable {
    public:
        /**
        * @brief Type of library
        */
        enum LibraryType {
            UNKNOWN = -1,
            DISPLAY = 0,
            GAME = 1,
            MENU = 2
        };

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
         * @brief Get the type of the library, @see arcade::api::library::IDLLoader
         * @return the type of the library
         */
        virtual LibraryType getType() const = 0;

    };
}

using LibraryType = arcade::api::library::ILibrary::LibraryType;

#endif //ARCADE_ILIBRARY_HPP
