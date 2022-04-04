/*
** EPITECH PROJECT, 2022
** AbstractDisplayModule.hpp
** File description:
** AbstractDisplayModule.hpp
*/

#ifndef ARCADE_ABSTRACTDISPLAYMODULE_HPP
#define ARCADE_ABSTRACTDISPLAYMODULE_HPP

#include "IDisplayModule.hpp"
#include "event/Events.hpp"
#include "renderer/Drawables.hpp"
#include <unordered_map>

namespace arcade::api {
    /**
     * @brief Abstract class for display module
     * @attention You will need to implements a getInstance method as a singleton
     * And implement a unique_ptr of the children class
     * @see IDisplayModule
     */
    class AbstractDisplayModule : public IDisplayModule {
    public:
        /**
         * @brief Construct an AbstractDisplayModule
         * @param name the name of the module (like NCurses/SFML etc)
         */
        explicit AbstractDisplayModule(const std::string &name)
        {
            this->_name = name;
            this->_size = {0, 0};
            this->_title = "";
            this->_framerateLimit = 60;
            this->_isOpen = false;
        }

        /**
         * @brief Get the name of the display module
         * @return the name
         */
        const std::string &getName() const override { return this->_name; };

        /**
         * @brief Get the type of the display module
         * @attention This will return only LibraryType::DISPLAY
         * @return the type of the display module
         */
        LibraryType getType() const override { return LibraryType::DISPLAY; };

        /**
         * @brief Get the size of the display
         * @return the size of the display
         */
        Vector2u getSize() const override { return this->_size; };

        /**
         * @brief Get the title of the display
         * @return the title of the display
         */
        const std::string &getTitle() const override { return this->_title; };

        /**
         * @brief Get the framerate limit of the display
         * @return the framerate limit
         */
        uint getFramerateLimit() const override { return this->_framerateLimit; };

    protected:
        /**
         * @brief Remove drawable from the map if they not updated for more than 5s
         * @return true if the drawable is removed, false otherwise
         */
        bool checkDrawable(const std::string &id)
        {
            if (this->_drawables.contains(id)) {
                long time = Time::getNanosecondsTime() - this->_drawables[id]->getLastUpdate();
                std::chrono::nanoseconds ns(time);
                std::chrono::seconds timeout(5);
                std::chrono::seconds actual = std::chrono::duration_cast<std::chrono::seconds>(ns);
                if (actual > timeout) {
                    this->_drawables.erase(id);
                    return true;
                }
            }
            return false;
        }

        // static std::unique_ptr<AbstractDisplayModule> _instance; /**< This need to be in children class*/
        std::string _name; /**< The name of the display module */
        Vector2u _size; /**< The size of the window */
        std::string _title; /**< The title of the window */
        std::size_t _framerateLimit; /**< The framerate limit of the window */
        bool _isOpen; /**< If the display module is open */
        std::unordered_map<std::string, std::unique_ptr<renderer::AbstractDrawable>> _drawables;
    };
}

#endif //ARCADE_ABSTRACTDISPLAYMODULE_HPP
