/*
** EPITECH PROJECT, 2022
** IDLManager.hpp
** File description:
** IDLManager.hpp
*/

#ifndef ARCADE_IDLMANAGER_HPP
#define ARCADE_IDLMANAGER_HPP

#include "api/IDisplayModule.hpp"
#include "api/IGameModule.hpp"
#include "api/event/SwitchEvent.hpp"
#include "api/utils/CircularVector.hpp"
#include <iostream>
#include <filesystem>

namespace arcade::api::library {
    /**
     * @brief Class to manage the libraries
     */
    class IDLManager {
    public:
        virtual ~IDLManager() = default;

        /**
         * @brief Load the library in the dirPath
         * @param dirPath the path of the directory containing the libraries
         * @throws arcade::api::ex::LibraryException if the library can't be loaded
         */
        virtual void loadLibrairies(const std::string &dirPath) = 0;

        /**
         * @brief Check if the library is a valid Game Library
         * @param path the path of the library
         * @return if the library is valid
         */
        virtual bool isGameLibrary(const std::string &path) const = 0;

        /**
         * @brief Check if the library is a valid Display Library
         * @param path the path of the library
         * @return if the library is valid
         */
        virtual bool isDisplayLibrary(const std::string &path) const = 0;

        /**
         * @brief Load the library passed as argument of arcade
         */
        virtual void loadArgumentLibrary(const std::string &path) = 0;

        /**
         * @brief Load a game library in the game module list
         * @attention Check library before @see isGameLibrary
         * @param path the path of the game library
         */
        virtual void loadGameLibrary(const std::string &path) = 0;

        /**
         * @brief Load a display library in the display module list
         * @attention Check library before @see isDisplayLibrary
         * @param path the path of the display library
         */
        virtual void loadDisplayLibrary(const std::string &path) = 0;

        /**
         * @brief Switch the current game
         * @param direction the direction of the switch
         * @return if the game has been switched correctly
         */
        virtual bool switchGame(const SwitchDirection &direction) = 0;

        /**
         * @brief Switch the current display
         * @param direction the direction of the switch
         * @return if the display has been switched correctly
         */
        virtual bool switchDisplay(const SwitchDirection &direction) = 0;

        /**
         * @brief Get the current game
         * @return the current game
         */
        virtual api::IGameModule *getGame() const = 0;

        /**
         * @brief Get the current display
         * @return the current display
         */
        virtual api::IDisplayModule *getDisplay() const = 0;

        /**
         * @brief Get the list of games
         * @return the list of games
         */
        virtual const std::vector<std::string> &getGames() const = 0;

        /**
         * @brief Get the list of displays
         * @return the list of displays
         */
        virtual const std::vector<std::string> &getDisplays() const = 0;

        /**
         * @brief Get the index of the actual game
         * @return the index of the actual game
         */
        virtual std::size_t getGameIndex() const = 0;

        /**
         * @brief Get the index of the actual display
         * @return the index of the actual display
         */
        virtual std::size_t getDisplayIndex() const = 0;

        /**
         * @brief Set the game index
         * @param gameIdx the new game index
         */
        virtual void setGame(int gameIdx) = 0;

        /**
         * @brief Set the display index
         * @param displayIdx the new display index
         */
        virtual void setDisplay(int displayIdx) = 0;

        /**
         * @brief Get the count of libraries
         * @return the count of libraries
         */
        virtual std::size_t totalCount() const = 0;

        /**
         * @brief Get the count of games
         * @return the count of games
         */
        virtual std::size_t gameCount() const = 0;

        /**
         * Get the count of display
         * @return the count of display
         */
        virtual std::size_t displayCount() const = 0;

        /**
         * @brief Unload all the libraries opened
         */
        virtual void unloadAll() = 0;
    };
}

#endif //ARCADE_IDLMANAGER_HPP
