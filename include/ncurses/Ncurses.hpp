/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
    #define NCURSES_HPP_
    #include "IDisplayModule.hpp"
    #include "IGameModule.hpp"
    #include "ncurses.h"
    #include "curses.h"

namespace arcade::api
{
    class Curses : public IDisplayModule {
        public:
            Curses();

            void init() override;
            void destroy() override;
            void display() override;
            void update() override;
            bool isOpen() const override;
            void clear() override;
            const std::string &getName() const override;
            static Curses *getInstance();
            bool pollEvent(event::IEvent &event) override;
            std::shared_ptr<arcade::api::Curses> entryPoint(void);
            inline LibraryType getType() const { return DISPLAY; }

        private:
            std::string _name;
            WINDOW *_window;
            bool _isOpen;
            static std::unique_ptr<Curses> _instance;
            std::shared_ptr<IGameModule> _game;
    };
}
#endif /* !NCURSES_HPP_ */