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
        _window = initscr();
        curs_set(false);
        nodelay(_window, true);
        _isOpen = true;
        subwin(_window, LINES - 5, COLS - 5, 5, 5); // HAUTEUR, LARGEUR, POS Y, POS X
        box(_window, ACS_VLINE, ACS_HLINE);
        while (_isOpen) {
            if (getch() == 'a') {
                destroy();
            }
            wrefresh(_window);
            mvwprintw(_window, 2, 5, "ALLO");
            // wclear(sub);
            // clear();

            // update();

        }
    }

    void arcade::api::Curses::destroy()
    {
        wclear(_window);
        endwin();
        _isOpen = false;
    }

    void arcade::api::Curses::display()
    {
    }

    void arcade::api::Curses::update()
    {
        wrefresh(_window);
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
        wclear(_window);
        wrefresh(_window);
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
    }

    std::shared_ptr<arcade::api::Curses> arcade::api::Curses::entryPoint(void)
    {
        // std::cout << "Curses entryPoint" << std::endl;
        std::string name = "Curses";
        std::shared_ptr<arcade::api::Curses> module = std::make_shared<arcade::api::Curses>(name);
        return module;
    }
}
