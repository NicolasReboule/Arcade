/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Core
*/

#include "core/Core.hpp"
#include "core/MainMenu.hpp"

arcade::Core::Core() : AbstractCore()
{
    this->_menu = nullptr;
}

void arcade::Core::init(const std::string &argLib)
{
    this->_manager.loadArgumentLibrary(argLib);
    this->_manager.loadLibrairies(this->_libDirPath);
    _menu = new menu::MainMenu(this);
    this->_display = this->_manager.getDisplay();
    _game = _menu;
    loadHighScore(SCORE_DIR);
    _display->init();
    _game->init();
}

void arcade::Core::run()
{
    std::unique_ptr<ArcadeEvent> event;
    while (_display->isOpen()) {
        if (_display->pollEvent(event))
            this->handleEvent(event);
        if (!_display->isOpen())
            break;
        _display->clear();
        _game->update(Time::getNanosecondsTime());
        _game->render(*_display);
        _display->display();
    }
    this->_display->destroy();
}

void arcade::Core::handleEvent(const std::unique_ptr<ArcadeEvent> &event)
{
    if (dynamic_cast<CloseEvent *>(event.get())) {
        if (_game->getType() == LibraryType::GAME)
            checkHighScore();
        this->_display->destroy();
        this->_game->destroy();
        return;
    }
    if (_game->getType() == LibraryType::MENU) {
        checkHighScore();
        _game->onEvent(*event);
        return;
    }
    if (dynamic_cast<SwitchEvent *>(event.get())) {
        auto tmp = dynamic_cast<SwitchEvent *>(event.get());
        std::cout << *tmp << std::endl;
        if (tmp->getType() == api::event::SwitchEvent::DISPLAY) {
            this->_display->destroy();
            this->_manager.switchDisplay(tmp->getDirection());
            this->_display = this->_manager.getDisplay();
            this->_display->init();
        } else if (tmp->getType() == api::event::SwitchEvent::GAME) {
            if (_game->getType() == LibraryType::GAME)
                checkHighScore();
            this->_game->destroy();
            this->_manager.switchGame(tmp->getDirection());
            this->_game = this->_manager.getGame();
            this->_game->init();
        }
        return;
    }
    if (dynamic_cast<RestartEvent *>(event.get())) {
        if (_game->getType() == LibraryType::GAME)
            checkHighScore();
        _game->restart();
        return;
    }
    if (dynamic_cast<LaunchMenuEvent *>(event.get())) {
        if (_game->getType() == LibraryType::GAME)
            checkHighScore();
        _game->destroy();
        _display->reset();
        _game = _menu;
        _game->init();
        return;
    }
    _game->onEvent(*event);
}

void arcade::Core::stop()
{
    this->_manager.unloadAll();
    delete _menu;
}

void arcade::Core::update()
{
    _game->destroy();
    _display->destroy();
    _game = _manager.getGame();
    _display = _manager.getDisplay();
    _display->init();
    _game->init();
}

arcade::api::library::IDLManager &arcade::Core::getDLManager()
{
    return _manager;
}

void arcade::Core::setUsername(const std::string &username)
{
    _username = username;
}

const std::string &arcade::Core::getUsername() const
{
    return _username;
}

void arcade::Core::checkHighScore()
{
    if (this->_game->getType() != LibraryType::GAME)
        return;
    std::size_t highScore = 0;
    if (this->hasHighScore(this->_game->getName()))
        highScore = this->getHighScore(this->_game->getName()).second;
    if (this->_game->getScore() > highScore)
        this->saveHighScore(this->_game->getName(), this->_game->getScore());
}

void arcade::Core::saveHighScore(const std::string &gameName, std::size_t score)
{
    if (!std::filesystem::exists(SCORE_DIR)) {
        if (!std::filesystem::create_directory(SCORE_DIR))
            std::cerr << "Arcade: Can't create score directory: " << SCORE_DIR << std::endl;
    }
    std::string fileName = SCORE_DIR + gameName + ".score";
    std::ofstream file(fileName, std::ios::out | std::ios::trunc);
    if (!file.is_open())
        throw api::ex::ArcadeException("Can't save the score: " + fileName);
    file << this->getUsername() << ":" << score;
    file.close();
}

void arcade::Core::loadHighScore(const std::string &dirPath)
{
    if (!std::filesystem::exists(dirPath))
        return;
    for (auto &entry: std::filesystem::directory_iterator(dirPath)) {
        if (!entry.path().string().ends_with(".score"))
            continue;
        std::ifstream file(entry.path());
        if (!file.is_open())
            continue;
        std::string gameName = entry.path().stem().string();
        std::string line;
        std::getline(file, line);
        file.close();
        std::string user = line.substr(0, line.find(':'));
        std::string score = line.substr(line.find(':') + 1);
        try {
            std::size_t scoreValue = std::stoul(score);
            this->_highScores[gameName] = std::make_pair(user, scoreValue);
        } catch (std::exception &e) {
            std::cerr << "Score is invalid: " << e.what() << std::endl;
        }
    }
}

bool arcade::Core::hasHighScore(const std::string &gameName)
{
    return this->_highScores.contains(gameName);
}

std::pair<std::string, std::size_t> arcade::Core::getHighScore(const std::string &gameName)
{
    if (!hasHighScore(gameName))
        return std::make_pair("", 0);
    return this->_highScores[gameName];
}