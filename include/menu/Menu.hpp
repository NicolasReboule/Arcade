/*
** EPITECH PROJECT, 2022
** menu.hpp
** File description:
** menu.hpp
*/

#pragma once

#include "api/AbstractGameModule.hpp"

namespace arcade::api {
    class Menu : public AbstractGameModule {
    public:
        Menu();

        ~Menu();

        bool isRunning() override;;

        inline LibraryType getType() const
        {
            return MENU;
        }

        static Menu *getInstance();

        void init() override;

        void update(std::size_t tick) override;

        void onEvent(event::IEvent &event) override;

        void render(IDisplayModule &display) override;

        void destroy() override;

        void restart() override;

    private:
        static std::unique_ptr<Menu> _instance;
        std::string _name;
    };
}
