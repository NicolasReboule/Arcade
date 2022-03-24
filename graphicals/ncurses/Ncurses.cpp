/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Ncurses
*/

#include "Ncurses.hpp"
#include "api/event/Events.hpp"
#include "api/library/ILibrary.hpp"

std::unique_ptr<arcade::api::Curses> arcade::api::Curses::_instance;

void arcade::api::Curses::init()
{
    _window = initscr();
    curs_set(false);
    nodelay(_window, true);
    _isOpen = true;
    subwin(_window, LINES - 5, COLS - 5, 5, 5); // HAUTEUR, LARGEUR, POS Y, POS X
    box(_window, ACS_VLINE, ACS_HLINE);
    while (_isOpen)
    {
        if (getch() == 'a')
        {
            destroy();
        }
        wrefresh(_window);
        mvwprintw(_window, 2, 5, "ALLO");
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

arcade::api::Curses *arcade::api::Curses::getInstance()
{
    if (_instance == nullptr)
        _instance = std::make_unique<Curses>();
    return _instance.get();
}

bool arcade::api::Curses::pollEvent(arcade::api::event::IEvent &event)
{
    int ch = getch();
    while (Curses::pollEvent(event)) {
        switch (ch) {
            case KEY_UP:
                event = event::SwitchEvent(event::SwitchEvent::GAME, event::SwitchEvent::NEXT);
                break;
            case KEY_DOWN:
                event = event::SwitchEvent(event::SwitchEvent::GAME, event::SwitchEvent::PREV);
                break;
            case KEY_RIGHT:
                event = event::SwitchEvent(event::SwitchEvent::DISPLAY, event::SwitchEvent::NEXT);
                break;
            case KEY_LEFT:
                event = event::SwitchEvent(event::SwitchEvent::DISPLAY, event::SwitchEvent::PREV);
                break;
            case 'z':
                event = event::KeyEvent(api::system::Keyboard::Z, api::system::Keyboard::KeyAction::PRESSED);
                break;
            case 'q':
                event = event::KeyEvent(api::system::Keyboard::Q, api::system::Keyboard::KeyAction::PRESSED);
                break;
            case 's':
                event = event::KeyEvent(api::system::Keyboard::S, api::system::Keyboard::KeyAction::PRESSED);
                break;
            case 'd':
                event = event::KeyEvent(api::system::Keyboard::D, api::system::Keyboard::KeyAction::PRESSED);
                break;
            case KEY_EXIT:
                event = event::KeyEvent(api::system::Keyboard::Escape, api::system::Keyboard::KeyAction::PRESSED);
                break;
            default:
                break;
        }
    }
    return true;
}

arcade::api::Curses::Curses()
{
    _name = "NCurses";
}

extern "C" arcade::api::Curses *entryPoint()
{
    return arcade::api::Curses::getInstance();
}