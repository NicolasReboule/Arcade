/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Nibbler
*/

#include "nibbler/Nibbler.hpp"
#include "api/event/SwitchEvent.hpp"

std::unique_ptr<arcade::api::Nibbler> arcade::api::Nibbler::_instance;

arcade::api::Nibbler::Nibbler(): AbstractGameModule("Nibbler")
{
    _direction = RIGHT;
    _time = 0;
}

void arcade::api::Nibbler::update(std::size_t tick)
{
    (void)tick;
    if (this->_time == 0)
        _time = tick + Time::getNanoTime(std::chrono::milliseconds(95));
    if (tick < this->_time)
        return;
    _time = tick + Time::getNanoTime(std::chrono::milliseconds(95));
    if (_direction == RIGHT)
        _gamesDrawables[0]->move(10, 0);
    if (_direction == LEFT)
        _gamesDrawables[0]->move(-10, 0);
    if (_direction == DOWN)
        _gamesDrawables[0]->move(0, 10);
    if (_direction == UP)
        _gamesDrawables[0]->move(0, -10);
}

arcade::api::Nibbler::~Nibbler()
{
    std::cout << "Nibbler : bye" << std::endl;
}

void arcade::api::Nibbler::restart()
{
    _direction = Direction::RIGHT;
    this->destroy();
    this->init();
}

extern "C" arcade::api::Nibbler *entryPoint()
{
    return arcade::api::Nibbler::getInstance();
}

arcade::api::Nibbler *arcade::api::Nibbler::getInstance()
{
    if (_instance == nullptr)
        _instance = std::make_unique<Nibbler>();
    return _instance.get();
}

bool arcade::api::Nibbler::isRunning()
{
    return false;
}

const std::string &arcade::api::Nibbler::getName() const
{
    return AbstractGameModule::getName();
}

void arcade::api::Nibbler::onEvent(arcade::api::event::IEvent &event)
{
    try {
        auto ev = dynamic_cast<const KeyEvent &>(event);
        if (ev.isPressed()) {
            if (ev.getKey() == KeyCode::Z)
                _direction = UP;
            if (ev.getKey() == KeyCode::S)
                _direction = DOWN;
            if (ev.getKey() == KeyCode::Q)
                _direction = LEFT;
            if (ev.getKey() == KeyCode::D)
                _direction = RIGHT;
        }
    } catch (std::bad_cast &e) {}
}

void arcade::api::Nibbler::render(arcade::api::IDisplayModule &display)
{
    for (auto &item: _drawables)
        display.draw(*item);
    for (auto &item : _gamesDrawables)
        display.draw(*item);
}

LibraryType arcade::api::Nibbler::getType() const
{
    return AbstractGameModule::getType();
}

void arcade::api::Nibbler::init()
{
    _time = 0;
    Sprite sprite("dirt.png", 'D');
    sprite.setPosition(200, 200);
    _gamesDrawables.push_back(std::make_unique<Sprite>(sprite));
}

void arcade::api::Nibbler::destroy()
{
    _drawables.clear();
    _gamesDrawables.clear();
}
