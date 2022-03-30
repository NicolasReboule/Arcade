/*
** EPITECH PROJECT, 2022
** IDisplayModule.hpp
** File description:
** IDisplayModule.hpp
*/

#ifndef ARCADE_IDISPLAYMODULE_HPP
#define ARCADE_IDISPLAYMODULE_HPP

#include "library/ILibrary.hpp"
#include "window/IWindow.hpp"
#include "renderer/IRenderTarget.hpp"
#include <iostream>
#include <chrono>

namespace arcade::api {
    /**
     * @brief Interface for all the display
     */
    class IDisplayModule : public library::ILibrary, public window::IWindow, public renderer::IRenderTarget {
    public:
        virtual ~IDisplayModule() = default;

        /**
         * @brief Init the display module
         */
        virtual void init() = 0;

        /**
         * @brief Destroy the display module
         */
        virtual void destroy() = 0;

        /**
         * @brief Close the display module
         */
        virtual void close() = 0;

        /**
         * Get the name of the display (for example: "SFML")
         * @return the name of the display
         */
        const std::string &getName() const override = 0;

        /**
         * @brief Get the type of the library
         * @attention Should always return LibraryType::DISPLAY
         * @return the type of the library
         */
        LibraryType getType() const override = 0;
    };
}

#endif //ARCADE_IDISPLAYMODULE_HPP
