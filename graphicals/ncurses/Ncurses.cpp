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

    const std::string &arcade::api::Curses::getName() const
    {
        return _name;
    }

    bool arcade::api::Curses::isOpen() const
    {
        return this->_isOpen;
    }

    void arcade::api::Curses::clear()
    {
    }

    arcade::api::IDisplayModule *arcade::api::Curses::getInstance()
    {
        return NULL;
    }

    bool arcade::api::Curses::pollEvent(arcade::api::event::IEvent &event)
    {
        return false;
    }

    arcade::api::Curses::Curses(const std::string &name)
    {
        _name = name;
        std::cout << "Constructor " << std::endl;
    }

    std::shared_ptr<arcade::api::Curses> arcade::api::Curses::entryPoint(void)
    {
        std::cout << "Curses entryPoint" << std::endl;
        std::string name = "Curses";
        std::shared_ptr<arcade::api::Curses> module = std::make_shared<arcade::api::Curses>(name);
        return module;
    }

}
