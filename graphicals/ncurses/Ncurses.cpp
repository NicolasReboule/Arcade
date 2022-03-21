/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Ncurses
*/

#include "Ncurses.hpp"

extern "C" {

    void arcade::api::Curses::init()
    {
        initscr();
        curs_set(false);
        nodelay(stdscr, true);
        std::cout << "NCURSES INIT" << std::endl;
        while (1) {
            if (getch() == 'a')
                exit (84);

        }
    }

    void arcade::api::Curses::destroy()
    {

    }

    void arcade::api::Curses::display()
    {

    }

    void arcade::api::Curses::update()
    {

    }

    void arcade::api::Curses::run()
    {

    }

    bool arcade::api::Curses::isOpen() const
    {
        return this->_isOpen;
    }

    void arcade::api::Curses::clear()
    {

    }

    arcade::api::Curses::Curses(const std::string &name, IGameModule &game): ADisplayModule(name, game)
    {
        _name = name;
        _game = std::make_shared<arcade::api::Curses>(game);
        std::cout << "Constructor " << std::endl;
    }

    arcade::api::Curses::Curses(const std::string &name): ADisplayModule(name)
    {
        _name = name;
        std::cout << "Constructor " << std::endl;
    }

    std::shared_ptr<arcade::api::Curses> entryPoint(void)
    {
        std::cout << "Curses entryPoint" << std::endl;
        std::string name = "Curses";
        std::shared_ptr<arcade::api::Curses> module = std::make_shared<arcade::api::Curses>(name);
        return module;
    }

}
