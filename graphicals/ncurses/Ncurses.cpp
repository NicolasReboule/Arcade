/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Ncurses
*/

#include "ncurses/Ncurses.hpp"
#include "ncurses/NcText.hpp"
#include "ncurses/NcSprite.hpp"
#include "ncurses/NcRectangle.hpp"

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
    if (this->checkDrawable(drawable.getId()) || !this->isOpen())
        return;
    try {
        auto rect = dynamic_cast<const Rectangle &>(drawable);
        if (!_drawables.contains(rect.getId()))
            _drawables[rect.getId()] = std::make_unique<ncurse::NcRectangle>(rect);
        else
            _drawables[rect.getId()]->update(rect);
        auto lol = dynamic_cast<ncurse::NcRectangle *>(_drawables[rect.getId()].get());
        lol->draw(stdscr);
    } catch (std::bad_cast &e) {}
    try {
        auto text = dynamic_cast<const Text &>(drawable);
        if (!_drawables.contains(text.getId()))
            _drawables[text.getId()] = std::make_unique<ncurse::NcText>(text);
        else
            _drawables[text.getId()]->update(text);
        auto lol = dynamic_cast<ncurse::NcText *>(_drawables[text.getId()].get());
        lol->draw(stdscr);
    } catch (std::bad_cast &e) {}
    try {
        auto sprite = dynamic_cast<const Sprite &>(drawable);
        if (!_drawables.contains(sprite.getId()))
            _drawables[sprite.getId()] = std::make_unique<ncurse::NcSprite>(sprite);
        else
            _drawables[sprite.getId()]->update(sprite);
        auto lol = dynamic_cast<ncurse::NcSprite *>(_drawables[sprite.getId()].get());
        lol->draw(stdscr);
    } catch (std::bad_cast &e) {}
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
            event = std::make_unique<CloseEvent>();
            break;
        case 'r':
            ev = true;
            event = std::make_unique<RestartEvent>();
            break;
        case 'm':
            ev = true;
            event = std::make_unique<LaunchMenuEvent>();
            break;
        case KEY_UP:
            ev = true;
            event = std::make_unique<SwitchEvent>(SwitchEvent::GAME, SwitchEvent::NEXT);
            break;
        case KEY_DOWN:
            ev = true;
            event = std::make_unique<SwitchEvent>(SwitchEvent::GAME, SwitchEvent::PREV);
            break;
        case KEY_RIGHT:
            ev = true;
            event = std::make_unique<SwitchEvent>(SwitchEvent::DISPLAY, SwitchEvent::NEXT);
            break;
        case KEY_LEFT:
            ev = true;
            event = std::make_unique<SwitchEvent>(SwitchEvent::DISPLAY, SwitchEvent::PREV);
            break;
        default:
            if (tolower(ch) >=  'a' && tolower(ch) <= 'z' ) {
                ev = true;
                auto code = static_cast<KeyCode>((KeyCode::A +
                                                  (tolower(ch - 'a'))));
                event = std::make_unique<KeyEvent>(code, KeyAction::PRESSED);
            }
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

void arcade::api::NCurses::reset()
{
}

extern "C" arcade::api::NCurses *entryPoint()
{
    return arcade::api::NCurses::getInstance();
}