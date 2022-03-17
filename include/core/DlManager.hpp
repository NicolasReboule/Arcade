/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** DlManager
*/

#ifndef DLMANAGER_HPP_
#define DLMANAGER_HPP_

#include "DlLoader.hpp"
#include "api/AGameModule.hpp"
#include "api/ADisplayModule.hpp"
#include <iostream>
#include <list>

namespace arcade {
    class DlManager
    {
        public:
            explicit DlManager(std::list<std::string>, std::list<std::string>);
            ~DlManager();
            void setActualGame(const std::string &);
            void setActualDisplay(const std::string &);
            inline std::shared_ptr<api::IGameModule> getActualGame() const {return _actualGame;};
            inline std::shared_ptr<api::IDisplayModule> getActualDisplay() const {return _actualDisplay;};
        private:
            std::list<DlLoader<api::IGameModule>> _gameLoaders;
            std::list<DlLoader<api::IDisplayModule>> _displayLoaders;
            std::list<std::shared_ptr<api::IGameModule>> _gameInstances;
            std::list<std::shared_ptr<api::IDisplayModule>> _displayInstances;
            std::shared_ptr<api::IGameModule> _actualGame;
            std::shared_ptr<api::IDisplayModule> _actualDisplay;
    };
}

#endif /* !DLMANAGER_HPP_ */
