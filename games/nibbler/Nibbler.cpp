/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Nibbler
*/

#include "nibbler/Nibbler.hpp"
#include "api/event/SwitchEvent.hpp"

std::unique_ptr<arcade::api::Nibbler> arcade::api::Nibbler::_instance;

arcade::api::Nibbler::Nibbler() : AbstractGameModule("Nibbler"),
                _food(Sprite("assets/food.png", '.'))
{
    _map = {
        {'#', MapType::BORDER},
        {'.', MapType::NONE},
        {'X', MapType::WALL},
        {'S', MapType::SNAKE},
        {'f', MapType::FOOD},
    };
    _direction = RIGHT;
    _time = 0;
}

void arcade::api::Nibbler::update(std::size_t tick)
{
    if (this->_time == 0)
        _time = tick + Time::getNanoTime(std::chrono::milliseconds(95));
    if (tick < this->_time)
        return;
    _time = tick + Time::getNanoTime(std::chrono::milliseconds(95));
    this->moveSnake();
    if (_direction == RIGHT)
        _snakeDrawables[0]->move(TTY_RATIO, 0);
    if (_direction == LEFT)
        _snakeDrawables[0]->move(-TTY_RATIO, 0);
    if (_direction == DOWN)
        _snakeDrawables[0]->move(0, TTY_RATIO);
    if (_direction == UP)
        _snakeDrawables[0]->move(0, -TTY_RATIO);
    addTail();
}

void arcade::api::Nibbler::addTail()
{
    if (_snakeDrawables[0]->getPosition().x == _food.getPosition().x &&
        _snakeDrawables[0]->getPosition().y == _food.getPosition().y) {
        Sprite sup("assets/red.png", 'S');
        sup.setPosition(-64, 0);
        _snakeDrawables.push_back(std::make_unique<Sprite>(sup));
    }
}

void arcade::api::Nibbler::moveSnake()
{
    if (this->_snakeDrawables.empty())
        return;
    for (auto it = _snakeDrawables.end() - 1; it != _snakeDrawables.begin(); it--) {
        if (it == _snakeDrawables.begin())
            return;
        it->get()->setPosition((it - 1)->get()->getPosition());
    }
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
    } catch (std::bad_cast &e) {
    }
}

void arcade::api::Nibbler::render(arcade::api::IDisplayModule &display)
{
    for (auto &item: _drawables)
        display.draw(*item);
    for (auto &item: _gamesDrawables)
        display.draw(*item);
    for (auto &item: _snakeDrawables)
        display.draw(*item);
    display.draw(_food);
}

LibraryType arcade::api::Nibbler::getType() const
{
    return AbstractGameModule::getType();
}

void arcade::api::Nibbler::init()
{
    _time = 0;
    this->initMap();
}

void arcade::api::Nibbler::initMap()
{
    float x = 0;
    float y = 0;
    Parser<MapType> parser("assets/nibbler.txt", _map, {60, 45});
    parser.parse();
    auto parse_map = parser.getMap();
    for (auto &item: parse_map) {
        x = 0;
        for (auto &type: item) {
            if (type == MapType::BORDER || type == MapType::WALL) {
                this->initBorder(x, y);
            } else if (type == MapType::SNAKE) {
                this->initSnake(x*TTY_RATIO, y*TTY_RATIO);
            } else if (type == MapType::FOOD) {
                this->initFood(x, y);
            }
            x++;
        }
        y++;
    }
}

void arcade::api::Nibbler::destroy()
{
    _drawables.clear();
    _gamesDrawables.clear();
    _snakeDrawables.clear();
}

void arcade::api::Nibbler::initBorder(float x, float y)
{
    std::unique_ptr<Sprite> wall = std::make_unique<Sprite>(
        "assets/dirt.png", 'X');
    wall->setPosition(x * TTY_RATIO, y * TTY_RATIO);
    _gamesDrawables.push_back(std::move(wall));
}

void arcade::api::Nibbler::initSnake(float x, float y)
{
    auto s1 = std::make_unique<Sprite>("assets/red.png", 'S');
    s1->setPosition(x, y);
    auto s2 = std::make_unique<Sprite>("assets/red.png", 'S');
    s2->setPosition(x -TTY_RATIO, y);
    auto s3 = std::make_unique<Sprite>("assets/red.png", 'S');
    s3->setPosition(x- 2 * TTY_RATIO, y);
    auto s4 = std::make_unique<Sprite>("assets/red.png", 'S');
    s4->setPosition(x- 3 * TTY_RATIO, y);
    _snakeDrawables.push_back(std::move(s1));
    _snakeDrawables.push_back(std::move(s2));
    _snakeDrawables.push_back(std::move(s3));
    _snakeDrawables.push_back(std::move(s4));
}

void arcade::api::Nibbler::initWall(float x, float y)
{
    std::unique_ptr<Sprite> wall = std::make_unique<Sprite>(
        "assets/dirt.png", 'X');
    wall->setPosition(x * TTY_RATIO, y * TTY_RATIO);
    _gamesDrawables.push_back(std::move(wall));
}

void arcade::api::Nibbler::initFood(float x, float y)
{
    _food.setPosition(x * TTY_RATIO, y * TTY_RATIO);
}
