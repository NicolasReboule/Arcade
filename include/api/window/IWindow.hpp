/*
** EPITECH PROJECT, 2022
** IWindow.hpp
** File description:
** IWindow.hpp
*/

#ifndef ARCADE_IWINDOW_HPP
#define ARCADE_IWINDOW_HPP

#include "api/event/IEvent.hpp"
#include "api/utils/Vector.hpp"
#include <memory>

namespace arcade::api::window {
    /**
     * @brief Interface for creating a window
     */
    class IWindow {
    public:
        virtual ~IWindow() = default;

        /**
         * @brief Create a window the a size and a title
         * @param size the window size
         * @param title the title of the window
         */
        virtual void createWindow(Vector2u size, const std::string &title) = 0;

        /**
         * @brief Check if the window is open
         * @return if the window is open
         */
        virtual bool isOpen() const = 0;

        /**
         * @brief Check if an event is available and pop it from the event list
         * Example: @code
         * bool pollEvent(std::unique_ptr<event::IEvent &event)
         * {
         *      //TODO: check if an event is available
         *      event = std::make_unique<KeyEvent>(KeyCode::A, KeyAction::PRESSED);
         * }
         * @endcode
         * TODO: potential event list, for now only one event
         * @param event The event will be stored in it, if available
         * @return if an event is available
         */
        virtual bool pollEvent(std::unique_ptr<event::IEvent> &event) = 0;

        /**
         * @brief Get the size of the window
         * @return the size of the window
         */
        virtual Vector2u getSize() const = 0;

        /**
         * @brief Set the size of the window
         * @param size the new size of the window
         */
        virtual void setSize(Vector2u size) = 0;

        /**
         * @brief Get the title of the window
         * @return the title of the window
         */
        virtual const std::string &getTitle() const = 0;

        /**
         * @brief Set the title of the window
         * @param title the new title
         */
        virtual void setTitle(const std::string &title) = 0;

        /**
         * @brief Set the icon of the window
         * @param path the path of the icon
         */
        virtual void setIcon(const std::string &path) = 0;

        /**
         * @brief Get the framerate limit of the window
         * @return the framerate limit
         */
        virtual uint getFramerateLimit() const = 0;

        /**
         * @brief Set the frame rate limit of the window
         * @param limit the limit of FPS
         */
        virtual void setFramerateLimit(uint limit) = 0;

        /**
         * @brief Display the window
         */
        virtual void display() = 0;

    };
}

#endif //ARCADE_IWINDOW_HPP
