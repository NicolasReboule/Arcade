/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Ncurses
*/

#include "ncurses/Ncurses.hpp"

std::unique_ptr<arcade::api::NCurses> arcade::api::NCurses::_instance;

void arcade::api::NCurses::init()
{
    this->createWindow({800, 600}, "Arcade | Ncurse");
    _isOpen = TRUE;
}

void arcade::api::NCurses::destroy()
{
    wclear(_window);
    close();
}

void arcade::api::NCurses::close()
{
    _isOpen = false;
    endwin();
}

void arcade::api::NCurses::clear(const arcade::api::renderer::Color &color)
{
    wclear(_window);
}

void arcade::api::NCurses::draw(const arcade::api::renderer::IDrawable &drawable)
{
}

void arcade::api::NCurses::createWindow(Vector2u size, const std::string &title)
{
    this->_size = {size.x/16, size.y/16};
    this->_title = title;
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    timeout(100);
    curs_set(0);
    nodelay(stdscr, TRUE);
    wclear(stdscr);
}

bool arcade::api::NCurses::pollEvent(std::unique_ptr<event::IEvent> &event)
{
    int ch = getch();
    bool ev = false;
    switch (ch) {
        case 27:
            ev = true;
            event = std::make_unique<event::CloseEvent>();
            break;
        case KEY_UP:
            ev = true;
            event = std::make_unique<event::SwitchEvent>(event::SwitchEvent::GAME, event::SwitchEvent::NEXT);
            break;
        case KEY_DOWN:
            ev = true;
            event = std::make_unique<event::SwitchEvent>(event::SwitchEvent::GAME, event::SwitchEvent::PREV);
            break;
        case KEY_RIGHT:
            ev = true;
            event = std::make_unique<event::SwitchEvent>(event::SwitchEvent::DISPLAY, event::SwitchEvent::NEXT);
            break;
        case KEY_LEFT:
            ev = true;
            event = std::make_unique<event::SwitchEvent>(event::SwitchEvent::DISPLAY, event::SwitchEvent::PREV);
            break;
        default:
            break;
    }
    return ev;
}

void arcade::api::NCurses::setSize(Vector2u size)
{
}

void arcade::api::NCurses::setTitle(const std::string &title)
{
}

void arcade::api::NCurses::setIcon(const std::string &path)
{
}

void arcade::api::NCurses::setFramerateLimit(uint limit)
{
}

void arcade::api::NCurses::display()
{
    refresh();
    timeout(100);
}

bool arcade::api::NCurses::isOpen() const
{
    return this->_isOpen;
}

arcade::api::NCurses *arcade::api::NCurses::getInstance()
{
    if (_instance == nullptr)
        _instance = std::make_unique<NCurses>();
    return _instance.get();
}

arcade::api::NCurses::NCurses() : AbstractDisplayModule("Ncurse")
{
    _window = nullptr;
}

extern "C" arcade::api::NCurses *entryPoint()
{
    return arcade::api::NCurses::getInstance();
}