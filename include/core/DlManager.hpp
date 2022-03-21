/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** DlManager
*/

#ifndef DLMANAGER_HPP_
#define DLMANAGER_HPP_

#include "DlLoader.hpp"
#include "api/IGameModule.hpp"
#include "api/IDisplayModule.hpp"
#include <iostream>
#include <list>

namespace arcade {
    class DlManager
    {
        public:
            explicit DlManager(std::list<std::string>, std::list<std::string>);
            ~DlManager();
            void setGameLoader(const std::string &);
            void setDisplayLoader(const std::string &);
            inline DlLoader<api::IGameModule> *getGameLoader() const {return _gameLoader;};
            inline DlLoader<api::IDisplayModule> *getDisplayLoader() const {return _displayLoader;};
        private:
            std::list<std::unique_ptr<DlLoader<api::IGameModule>>> _gameLoaders;
            std::list<std::unique_ptr<DlLoader<api::IDisplayModule>>> _displayLoaders;
            DlLoader<api::IGameModule> *_gameLoader;
            DlLoader<api::IDisplayModule> *_displayLoader;
    };
}

#endif /* !DLMANAGER_HPP_ */
