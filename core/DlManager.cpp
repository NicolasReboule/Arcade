/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** DLManager
*/

#include "DlManager.hpp"

arcade::DlManager::DlManager(std::list<std::string> games,
std::list<std::string> displays)
{
    for (auto it = games.begin(); it != games.end(); it++)
        _gameLoaders.push_back(std::make_unique<DlLoader<api::IGameModule>>(it->c_str()));
    for (auto it = displays.begin(); it != displays.end(); it++)
        _displayLoaders.push_back(std::make_unique<DlLoader<api::IDisplayModule>>(it->c_str()));
}

arcade::DlManager::~DlManager()
{
}

void arcade::DlManager::setGameLoader(const std::string &name)
{
    for (auto it = _gameLoaders.begin(); it != _gameLoaders.end(); it++) {
        if (it->get()->getInstance()->getName() == name) {
            _gameLoader = it->get();
            return;
        }
    }
}

void arcade::DlManager::setDisplayLoader(const std::string &name)
{
    for (auto it = _displayLoaders.begin(); it != _displayLoaders.end(); it++)
        if (it->get()->getInstance()->getName() == name) {
            _displayLoader = it->get();
            return;
        }
}