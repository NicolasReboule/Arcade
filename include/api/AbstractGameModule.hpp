/*
** EPITECH PROJECT, 2022
** AbstractGameModule.hpp
** File description:
** AbstractGameModule.hpp
*/

#ifndef ARCADE_ABSTRACTGAMEMODULE_HPP
#define ARCADE_ABSTRACTGAMEMODULE_HPP

#include "IGameModule.hpp"
#include "event/Events.hpp"
#include "renderer/Drawables.hpp"
#include "ex/ArcadeException.hpp"
#include "utils/Random.hpp"
#include "utils/Parser.hpp"
#include <list>

namespace arcade::api {
    /**
     * @brief Abstract class for game module
     * @attention You will need to implements a getInstance method as a singleton
     * And implement a unique_ptr of the children class
     * @see IGameModule
     */
    class AbstractGameModule : public IGameModule {
    public:
        /**
         * @brief Construct an abstract game module with a name
         * @param name the name of the game
         */
        explicit AbstractGameModule(const std::string &name)
        {
            this->_name = name;
            this->_isRunning = true;
        }

        /**
         * @brief Get the name of the library
         * @return the name of the library
         */
        const std::string &getName() const override
        {
            return this->_name;
        }

        /**
         * @brief Get the type of the library
         * @attention Should always return LibraryType::GAME
         * @return the type of the library
         */
        LibraryType getType() const override
        {
            return LibraryType::GAME;
        }

        /**
         * @brief Check if the game is running
         * @return if the game is running
         */
        bool isRunning() override
        {
            return this->_isRunning;
        }

    protected:
        std::string _name; /**< The name of the library */
        bool _isRunning; /**< If the game is running */
        std::list<std::unique_ptr<renderer::AbstractDrawable>> _drawables; /**< The list of drawable, unique_ptr used for inheritance call */
    };
}

#endif //ARCADE_ABSTRACTGAMEMODULE_HPP
