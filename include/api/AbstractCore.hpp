/*
** EPITECH PROJECT, 2022
** AbstractCore.hpp
** File description:
** AbstractCore.hpp
*/

#ifndef ARCADE_ABSTRACTCORE_HPP
#define ARCADE_ABSTRACTCORE_HPP

#include "api/API.hpp"
#include <memory>

namespace arcade::api {
    /**
     * @brief Interface for the core
     */
    class AbstractCore {
    public:
        /**
         * @brief Construct an abstract core
         */
        AbstractCore() {
            this->_display = nullptr;
            this->_game = nullptr;
            this->_libDirPath = "./lib";
        }
        ~AbstractCore() = default;

        /**
         * @brief Init the core with the library passed as argument of the program
         * @param libPath the lib passed as argument of the program
         */
        virtual void init(const std::string &libPath) = 0;

        /**
         * @brief Handle the event received by the display
         * @param event the event of the display module
         */
        virtual void handleEvent(const std::unique_ptr<ArcadeEvent> &event) = 0;

        /**
         * @brief Run the core
         */
        virtual void run() = 0;

        /**
         * @brief Stop the core
         */
        virtual void stop() = 0;

    protected:
        IDisplayModule *_display; /**< The actual display */
        IGameModule *_game; /**< The actual game */
        std::string _libDirPath; /**< The path of the lib directory */
    };
}

#endif //ARCADE_ABSTRACTCORE_HPP
