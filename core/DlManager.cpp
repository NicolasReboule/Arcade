/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** DLManager
*/

#include "core/DlManager.hpp"

arcade::DlManager::DlManager()
{
    this->_count = 0;
}

void arcade::DlManager::loadLibrairies(const std::string &dirPath)
{
    _path = dirPath;
    for (auto &it: std::filesystem::directory_iterator(_path)) {
        try {
            if (isDisplayLibrary(it.path().string())) {
                loadDisplayLibrary(it.path().string());
            } else if (isGameLibrary(it.path().string()))
                loadGameLibrary(it.path().string());
            else
                std::cerr << "Error" << std::endl;
        } catch (arcade::api::ex::LibraryAlreadyLoaded &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    if (_count)
        throw api::ex::ArcadeException("Error");
    if (_gameModules.empty())
        throw api::ex::ArcadeException("Error");
    if (_displayModules.empty())
        throw api::ex::ArcadeException("Error");
}

bool arcade::DlManager::isGameLibrary(const std::string &path) const
{
    arcade::DlLoader<api::IGameModule> loader;
    try {
        loader.load(path);
        loader.loadInstance();
        loader.unload();
    } catch (api::ex::LibraryNotFound &e) {
        return false;
    } catch (api::ex::LibraryEntryPointNotFound &e) {
        return false;
    }
    return true;
}

bool arcade::DlManager::isDisplayLibrary(const std::string &path) const
{
    arcade::DlLoader<api::IDisplayModule> loader;
    try {
        loader.load(path);
        loader.loadInstance();
        loader.unload();
    } catch (api::ex::LibraryNotFound &e){
        return false;
    } catch (api::ex::LibraryEntryPointNotFound &e) {
        return false;
    }
    return true;
}

void arcade::DlManager::loadArgumentLibrary(const std::string &path)
{
    if (!isDisplayLibrary(path))
        throw arcade::api::ex::ArcadeException("Error");
}

void arcade::DlManager::loadGameLibrary(const std::string &path)
{
    std::for_each(_gameModules.getVector().begin(), _gameModules.getVector().end(), [&path](DlLoader<api::IGameModule> &loader){
        if (loader.getPath() == path)
            throw arcade::api::ex::LibraryAlreadyLoaded("Error");
    });
    arcade::DlLoader<api::IGameModule> loader;
    loader.load(path);
    loader.loadInstance();
    std::for_each(_gameModules.getVector().begin(), _gameModules.getVector().end(), [&loader](DlLoader<api::IGameModule> &ld){
        if (*ld == *loader) {
            loader.unload();
            throw arcade::api::ex::LibraryAlreadyLoaded("Error");
        }
    });
    _gameModules.push(loader);
    _count++;
}

void arcade::DlManager::loadDisplayLibrary(const std::string &path)
{
    arcade::DlLoader<api::IDisplayModule> loader;
    std::for_each(_displayModules.getVector().begin(), _displayModules.getVector().end(), [&path](DlLoader<api::IDisplayModule> &loader){
        if (loader.getPath() == path)
            throw arcade::api::ex::LibraryAlreadyLoaded("Error");
    });

    loader.load(path);
    loader.loadInstance();
    std::for_each(_displayModules.getVector().begin(), _displayModules.getVector().end(), [&loader](DlLoader<api::IDisplayModule> &ld){
        if (*ld == *loader) {
            loader.unload();
            throw arcade::api::ex::LibraryAlreadyLoaded("Error");
        }
    });
    _count++;
    _displayModules.push(loader);
}

bool arcade::DlManager::switchGame(const SDirection direction)
{
    if (direction == SDirection::NEXT)
        this->_gameModules++;
    else
        this->_gameModules--;
    return true;
}

bool arcade::DlManager::switchDisplay(const SDirection direction)
{
    if (direction == SDirection::NEXT)
        this->_displayModules++;
    else
        this->_displayModules--;
    return true;
}

arcade::api::IGameModule *arcade::DlManager::getGame() const
{
    return *(*this->_gameModules);
}

arcade::api::IDisplayModule *arcade::DlManager::getDisplay() const
{
    return this->_displayModules.get().getInstance();
}

size_t arcade::DlManager::totalCount() const
{
    return this->displayCount() + this->gameCount();
}

size_t arcade::DlManager::gameCount() const
{
    return this->_gameModules.size();
}

size_t arcade::DlManager::displayCount() const
{
    return this->_displayModules.size();
}
