/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** sfml
*/

#include "sfml/Sfml.hpp"

arcade::api::Sfml *arcade::api::Sfml::_instance;


arcade::api::Sfml::Sfml() : AbstractDisplayModule("Sfml")
{
}

void arcade::api::Sfml::clear(const arcade::api::renderer::Color &color)
{
    _window.clear(sf::Color(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha()));
}

void arcade::api::Sfml::draw(const arcade::api::renderer::IDrawable &drawable)
{
}

void arcade::api::Sfml::createWindow(Vector2u size, const std::string &title)
{
    _window.create(sf::VideoMode(size.x, size.y), title);
}

bool arcade::api::Sfml::pollEvent(std::unique_ptr<event::IEvent> &event)
{
    sf::Event e = sf::Event();
    while (this->_window.pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
            event = std::make_unique<CloseEvent>();
            return true;
        }
        if (e.type == sf::Event::KeyPressed) {
            if (e.key.code == sf::Keyboard::Escape) {
                event = std::make_unique<CloseEvent>();
                return true;
            } else if (e.key.code == sf::Keyboard::Up) {
                event = std::make_unique<SwitchEvent>(SwitchType::GAME, SwitchDirection::NEXT);
                return true;
            } else if (e.key.code == sf::Keyboard::Down) {
                event = std::make_unique<SwitchEvent>(SwitchType::GAME, SwitchDirection::PREV);
                return true;
            } else if (e.key.code == sf::Keyboard::Left) {
                event = std::make_unique<SwitchEvent>(SwitchType::DISPLAY, SwitchDirection::PREV);
                return true;
            } else if (e.key.code == sf::Keyboard::Right) {
                event = std::make_unique<SwitchEvent>(SwitchType::DISPLAY, SwitchDirection::NEXT);
                return true;
            } else if (e.key.code == sf::Keyboard::R) {
                event = std::make_unique<RestartEvent>();
                return true;
            } else if (e.key.code == sf::Keyboard::M) {
                event = std::make_unique<LaunchMenuEvent>();
                return true;
            }
            auto code = static_cast<KeyCode>(e.key.code);
            event = std::make_unique<KeyEvent>(code, KeyAction::PRESSED);
            return true;
        } else if (e.type == sf::Event::KeyReleased) {
            auto code = static_cast<KeyCode>(e.key.code);
            event = std::make_unique<KeyEvent>(code, KeyAction::RELEASED);
            return true;
        }
    }
    return false;
}

void arcade::api::Sfml::setSize(Vector2u size)
{
    this->_window.setSize({size.x, size.y});
    _size = size;
}


void arcade::api::Sfml::setTitle(const std::string &title)
{
    this->_window.setTitle(title);
    _title = title;
}

void arcade::api::Sfml::setIcon(const std::string &path)
{
}

void arcade::api::Sfml::setFramerateLimit(uint limit)
{
    this->_window.setFramerateLimit(limit);
}

void arcade::api::Sfml::init()
{
    createWindow({800, 600}, "Arcade | Sfml");
    setFramerateLimit(60);
}

extern "C" arcade::api::Sfml *entryPoint(void)
{
    return arcade::api::Sfml::getInstance();
}

arcade::api::Sfml *arcade::api::Sfml::getInstance()
{
    if (_instance == nullptr)
        _instance = new Sfml();
    return _instance;
}

bool arcade::api::Sfml::isOpen() const
{
    return this->_window.isOpen();
}

void arcade::api::Sfml::destroy()
{
    close();
}

void arcade::api::Sfml::close()
{
    if (isOpen())
        _window.close();
}

void arcade::api::Sfml::display()
{
    _window.display();
}

void arcade::api::Sfml::reset()
{
}
