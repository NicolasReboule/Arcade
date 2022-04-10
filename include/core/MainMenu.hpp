/*
** EPITECH PROJECT, 2022
** MainMenu.hpp
** File description:
** MainMenu.hpp
*/

#pragma once

#include "api/AbstractGameModule.hpp"
#include "core/Core.hpp"
#include <vector>

namespace arcade::menu {
    class MainMenu : public api::AbstractGameModule {
    public:
        explicit MainMenu(Core *core);
        ~MainMenu() override = default;

        LibraryType getType() const override;

        void init() override;

        void update(std::size_t tick) override;

        void onEvent(api::event::IEvent &event) override;

        void render(api::IDisplayModule &display) override;

        void destroy() override;

        void restart() override;

    private:
        Core *_core;
        std::size_t _gameIdx;
        std::size_t _displayIdx;
        Text _username;
        bool _hasUsername;
        bool _onDisplay;
        bool _gameSelected;
        bool _displaySelected;
        std::vector<std::unique_ptr<Text>> _displayDrawables;
        std::vector<std::unique_ptr<Text>> _gamesDrawables;
        std::list<std::unique_ptr<Text>> _highscoresDrawables;
        Text *_current;

        void initGlobalMenu();
        void initDisplays();
        void initGames();
        void initHighscore();
    };
}