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
        virtual ~AbstractCore() = default;

        /**
         * @brief Init the core with the library passed as argument of the program
         * @param libPath the lib passed as argument of the program
         */
        virtual void init(const std::string &libPath) = 0;

        /**
         * @brief Destroy the current game & display.
         * Update the display & game to the current getters and init them
         */
        virtual void update() = 0;

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

        /**
         * @brief Get the dlmanager
         * @return the dlmanager
         */
        virtual library::IDLManager &getDLManager() = 0;

        /**
         * @brief Set the username of the player
         * @param username the username of the player
         */
        virtual void setUsername(const std::string &username) = 0;

        /**
         * @brief Get the username of the player
         * @return the username of the player
         */
        virtual const std::string &getUsername() const = 0;

    protected:
        IDisplayModule *_display; /**< The actual display */
        IGameModule *_game; /**< The actual game */
        std::string _libDirPath; /**< The path of the lib directory */
        std::string _username;
    };
}

#endif //ARCADE_ABSTRACTCORE_HPP
