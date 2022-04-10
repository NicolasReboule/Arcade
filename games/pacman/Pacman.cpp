/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Pacman
*/

#include "pacman/Pacman.hpp"

std::unique_ptr<arcade::api::Pacman> arcade::api::Pacman::_instance;

void arcade::api::Pacman::restart()
{
    _direction = NOPE;
    _score = 0;
    _isGod = false;
    this->destroy();
    this->init();
}

arcade::api::Pacman::Pacman(): AbstractGameModule("Pacman"),
                    _pac(Sprite("assets/pacman.png", 'P'))
{
    _map = {
        {'#', MapType::BORDER},
        {' ', MapType::NONE},
        {'P', MapType::PAC},
        {'-', MapType::FOOD},
        {'C', MapType::PACGUM},
        {'G', MapType::GHOST},
        {'+', MapType::PORTAL},
    };
    _pac.setOrigin(RATIO_CENTER, RATIO_CENTER);
    _direction = NOPE;
    _time = 0;
    _isWin = false;
    _isGod = false;
}

void arcade::api::Pacman::initPortal(float x, float y)
{
    Sprite portal("assets/red.png", 'O');
    portal.setColor(ArcadeColor::Blue);
    portal.setOrigin(RATIO_CENTER, RATIO_CENTER);
    portal.setPosition(x, y);
    _portalDrawables.push_back(std::make_unique<Sprite>(portal));
}

void arcade::api::Pacman::initMap()
{
    float x = 0;
    float y = RATIO_CENTER;
    Parser<MapType> parser("assets/pacman.txt", _map, {60, 45});
    parser.parse();
    _parsed = parser.getMap();
    for (auto &item: _parsed) {
        x = RATIO_CENTER;
        for (auto &type: item) {
            if (type == MapType::BORDER) {
                this->initBorder(x, y);
            } else if (type == MapType::PAC) {
                this->initPac(x, y);
            } else if (type == MapType::FOOD) {
                this->initFood(x, y);
            } else if (type == MapType::GHOST) {
                this->initGhost(x, y);
            } else if (type == MapType::PORTAL) {
                this->initPortal(x, y);
            } else if (type == MapType::PACGUM)
                this->initPacgum(x, y);
            x+=TTY_RATIO;
        }
        y+=TTY_RATIO;
    }
}

void arcade::api::Pacman::initBorder(float x, float y)
{
    std::unique_ptr<Sprite> wall = std::make_unique<Sprite>(
        "assets/brick.png", 'X');
    wall->setPosition(x, y);
    wall->setOrigin(RATIO_CENTER, RATIO_CENTER);
    wall->setColor(ArcadeColor::Magenta);
    _pacmanDrawables.push_back(std::move(wall));
}

void arcade::api::Pacman::initPac(float x, float y)
{
    _pac.setPosition(x, y);
    _pac.setColor(ArcadeColor::Yellow);
}

void arcade::api::Pacman::initGhost(float x, float y)
{
    (void)x;
    (void)y;
}

void arcade::api::Pacman::initFood(float x, float y)
{
    std::unique_ptr<Sprite> food = std::make_unique<Sprite>(
        "assets/pacmanBoof.png", '.');
    food->setPosition(x, y);
    food->setOrigin(RATIO_CENTER, RATIO_CENTER);
    food->setColor(ArcadeColor::Green);
    _foodDrawables.push_back(std::move(food));
}

void arcade::api::Pacman::initPacgum(float x, float y)
{
    std::unique_ptr<Sprite> pacgum = std::make_unique<Sprite>(
        "assets/pacgum.png", '.');
    pacgum->setPosition(x, y);
    pacgum->setSymbol('o');
    pacgum->setOrigin(RATIO_CENTER, RATIO_CENTER);
    pacgum->setColor(ArcadeColor::Red);
    _foodDrawables.push_back(std::move(pacgum));
}

void arcade::api::Pacman::initScore()
{
    Text score("Your score: " + std::to_string(_score), "assets/walkthemoon.ttf", ArcadeColor::Yellow);
    score.setPosition(200, 50);
    _scoreDrawables.push_back(std::make_unique<Text>(score));
}

arcade::api::Pacman::~Pacman()
{
    std::cout << "Pacman : bye" << std::endl;
}

bool arcade::api::Pacman::isRunning()
{
    return AbstractGameModule::isRunning();
}

void arcade::api::Pacman::clearCase()
{
    Vector2f actual = _pac.getPosition();
    auto it = _foodDrawables.begin();
    for (; it != _foodDrawables.end(); it++) {
        if (actual.x == it->get()->getPosition().x && actual.y == it->get()->getPosition().y) {
            if (it->get()->getSymbol() == 'o') {
                _isGod = true;
                _stateTime = _time;
                _score += 1000;
            } else
                _score += 100;
            _scoreDrawables[0]->setText("Your score: " + std::to_string(_score));
            _foodDrawables.erase(it);
            break;
        }
    }
}

void arcade::api::Pacman::teleport()
{
    Vector2f actual = _pac.getPosition();
    auto it = _portalDrawables.begin();
    int i = 0;
    for (; it != _portalDrawables.end(); it++, i++) {
        if (actual.x == it->get()->getPosition().x && actual.y == it->get()->getPosition().y) {
            if (i % 2 == 0)
                _pac.setPosition((it + 1)->get()->getPosition());
            else
                _pac.setPosition((it - 1)->get()->getPosition());
            break;
        }
    }
}

void arcade::api::Pacman::init()
{
    _time = 0;
    _stateTime = 0;
    _score = 0;
    this->initMap();
    this->initScore();
    this->_isWin = false;
    Text text("You Won !", "assets/walkthemoon.ttf", ArcadeColor::Yellow);
    text.setPosition(ARCADE_WIDTH / 2, ARCADE_HEIGHT / 2);
    _winDrawables.push_back(std::make_unique<Text>(text));
}

void arcade::api::Pacman::update(std::size_t tick)
{
    if (this->_time == 0)
        _time = tick + Time::getNanoTime(std::chrono::milliseconds(95));
    if (tick < this->_time)
        return;
    _time = tick + Time::getNanoTime(std::chrono::milliseconds(95));
    if (_time >= _stateTime + Time::getNanoTime(std::chrono::seconds(5)))
        _isGod = false;
    Vector2f actual = _pac.getPosition();
    if (_direction == RIGHT && \
        _parsed[actual.y / TTY_RATIO][(actual.x + TTY_RATIO) / TTY_RATIO] != MapType::BORDER) {
        _pac.setFlipType(FlipType::NONE);
        _pac.setRotation(0);
        _pac.move(TTY_RATIO, 0);
        _direction = NOPE;
        clearCase();
        teleport();
    }
    if (_direction == LEFT && \
        _parsed[actual.y / TTY_RATIO][(actual.x - TTY_RATIO) / TTY_RATIO] != MapType::BORDER) {
        _pac.setFlipType(FlipType::HORIZONTAL);
        _pac.move(-TTY_RATIO, 0);
        _pac.setRotation(-180);
        _direction = NOPE;
        clearCase();
        teleport();
    }
    if (_direction == DOWN && \
        _parsed[(actual.y + TTY_RATIO) / TTY_RATIO][actual.x / TTY_RATIO] != MapType::BORDER) {
        _pac.move(0, TTY_RATIO);
        _pac.setRotation(90);
        _direction = NOPE;
        clearCase();
        teleport();
    }
    if (_direction == UP && \
        _parsed[(actual.y - TTY_RATIO) / TTY_RATIO][actual.x / TTY_RATIO] != MapType::BORDER) {
        _pac.move(0, -TTY_RATIO);
        _pac.setRotation(-90);
        _direction = NOPE;
        clearCase();
        teleport();
    }
    if (_foodDrawables.empty())
        _isWin = true;
}

void arcade::api::Pacman::onEvent(arcade::api::event::IEvent &event)
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

void arcade::api::Pacman::render(arcade::api::IDisplayModule &display)
{
    if (!_isWin) {
        for (auto &item : _drawables)
            display.draw(*item);
        for (auto &item : _gamesDrawables)
            display.draw(*item);
        for (auto &item : _pacmanDrawables)
            display.draw(*item);
        for (auto &item : _foodDrawables)
            display.draw(*item);
        for (auto &item : _portalDrawables)
            display.draw(*item);
        for (auto &item : _scoreDrawables)
            display.draw(*item);
        display.draw(_pac);
    } else {
        for (auto &item : _winDrawables)
            display.draw(*item);
    }
}

void arcade::api::Pacman::destroy()
{
    _drawables.clear();
    _pacmanDrawables.clear();
    _foodDrawables.clear();
    _gamesDrawables.clear();
    _portalDrawables.clear();
    _winDrawables.clear();
    _scoreDrawables.clear();
}

extern "C" arcade::api::Pacman *entryPoint()
{
    return arcade::api::Pacman::getInstance();
}

arcade::api::Pacman *arcade::api::Pacman::getInstance()
{
    if (_instance == nullptr)
        _instance = std::make_unique<Pacman>();
    return _instance.get();
}
