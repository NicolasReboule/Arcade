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
    for (auto it = games.begin(); it != games.end(); it++) {
        DlLoader<api::IGameModule> tmp;
        _gameInstances.push_back(tmp.getInstance(it->c_str()));
        _gameLoaders.push_back(tmp);
    }
    for (auto it = displays.begin(); it != displays.end(); it++) {
        DlLoader<api::IDisplayModule> tmp;
        _displayInstances.push_back(tmp.getInstance(it->c_str()));
        _displayLoaders.push_back(tmp);
    }
}

arcade::DlManager::~DlManager()
{
    _actualGame = nullptr;
    _actualDisplay = nullptr;
    while (!_gameInstances.empty())
        _gameInstances.pop_back();
    while (!_displayInstances.empty())
        _displayInstances.pop_back();
    for (auto it = _gameLoaders.begin(); it != _gameLoaders.end(); it++)
        it->closeInstance();
    for (auto it = _displayLoaders.begin(); it != _displayLoaders.end(); it++)
        it->closeInstance();
}

void arcade::DlManager::setActualGame(const std::string &name)
{
    for (auto it = _gameInstances.begin(); it != _gameInstances.end(); it++)
        if (it->get()->getName() == name) {
            _actualGame = *it;
            return;
        }
}

void arcade::DlManager::setActualDisplay(const std::string &name)
{
    for (auto it = _displayInstances.begin(); it != _displayInstances.end(); it++)
        if (it->get()->getName() == name) {
            _actualDisplay = *it;
            return;
        }
}