/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** DlManager
*/

#ifndef DLMANAGER_HPP_
#define DLMANAGER_HPP_

#include "DlLoader.hpp"
#include "api/library/IDLManager.hpp"

namespace arcade {
    class DlManager : public api::library::IDLManager {
    public:
        DlManager();

        void loadLibrairies(const std::string &dirPath) override;

        bool isGameLibrary(const std::string &path) const override;

        bool isDisplayLibrary(const std::string &path) const override;

        void loadArgumentLibrary(const std::string &path) override;

        void loadGameLibrary(const std::string &path) override;

        void loadDisplayLibrary(const std::string &path) override;

        bool switchGame(const SwitchDirection &direction) override;

        bool switchDisplay(const SwitchDirection &direction) override;

        api::IGameModule *getGame() const override;

        api::IDisplayModule *getDisplay() const override;

        std::size_t totalCount() const override;

        std::size_t gameCount() const override;

        std::size_t displayCount() const override;

        void unloadAll() override;

        bool isMainMenuLibrary(const std::string &path) const override;

        void loadMainMenuLibrary(const std::string &path) override;

        api::IGameModule *getMainMenu() const override;

    private:
        std::string _path;
        std::size_t _count;
        CircularVector<DlLoader<api::IDisplayModule>> _displayModules;
        CircularVector<DlLoader<api::IGameModule>> _gameModules;
        DlLoader<api::IGameModule> _mainMenu;
    };
}

#endif /* !DLMANAGER_HPP_ */
