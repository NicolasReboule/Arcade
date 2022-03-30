/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Sdl2
*/

#include "sdl2/Sdl2.hpp"

std::unique_ptr<arcade::api::Sdl2> arcade::api::Sdl2::_instance;

arcade::api::Sdl2::Sdl2() : AbstractDisplayModule("Sdl2")
{
    this->_renderer = nullptr;
    this->_window = nullptr;
}

void arcade::api::Sdl2::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        exit(84);
    }
    createWindow({800, 600}, "Arcade | Sdl2");
    _isOpen = true;
}

void arcade::api::Sdl2::destroy()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    close();
}

void arcade::api::Sdl2::close()
{
    if (isOpen())
        SDL_Quit();
    this->_isOpen = false;
}

void arcade::api::Sdl2::clear(const arcade::api::renderer::Color &color)
{
    SDL_SetRenderDrawColor(_renderer, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    SDL_RenderClear(_renderer);
}

void arcade::api::Sdl2::draw(const arcade::api::renderer::IDrawable &drawable)
{
}

void arcade::api::Sdl2::createWindow(Vector2u size, const std::string &title)
{
    if (SDL_CreateWindowAndRenderer((int) size.x, (int) size.y, SDL_WINDOW_SHOWN, &_window, &_renderer) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        SDL_Quit();
    }
    setTitle(title);
}

bool arcade::api::Sdl2::isOpen() const
{
    return this->_isOpen;
}

bool arcade::api::Sdl2::pollEvent(std::unique_ptr<ArcadeEvent> &event)
{
    bool ev = false;
    SDL_Event e;
    event::IEvent *tmp;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            event = std::make_unique<event::CloseEvent>();
            return true;
        }
        if (e.key.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_ESCAPE:
                    ev = true;
                    event = std::make_unique<event::CloseEvent>();
                    break;
                case SDLK_UP:
                    ev = true;
                    event = std::make_unique<event::SwitchEvent>(event::SwitchEvent::GAME, event::SwitchEvent::NEXT);
                    break;
                case SDLK_DOWN:
                    ev = true;
                    event = std::make_unique<event::SwitchEvent>(event::SwitchEvent::GAME, event::SwitchEvent::PREV);
                    break;
                case SDLK_RIGHT:
                    ev = true;
                    event = std::make_unique<event::SwitchEvent>(event::SwitchEvent::DISPLAY, event::SwitchEvent::NEXT);
                    break;
                case SDLK_LEFT:
                    ev = true;
                    event = std::make_unique<event::SwitchEvent>(event::SwitchEvent::DISPLAY, event::SwitchEvent::PREV);
                    break;
            }
        }
    }
    return ev;
}

void arcade::api::Sdl2::setSize(Vector2u size)
{
    this->_size = size;
    SDL_SetWindowSize(this->_window, (int) size.x, (int) size.y);
}

void arcade::api::Sdl2::setTitle(const std::string &title)
{
    SDL_SetWindowTitle(_window, title.c_str());
    this->_title = title;
}

void arcade::api::Sdl2::setIcon(const std::string &path)
{
    SDL_Surface *Icon = SDL_LoadBMP(path.c_str());
    SDL_SetWindowIcon(_window, Icon);
    SDL_FreeSurface(Icon);
}

void arcade::api::Sdl2::setFramerateLimit(uint limit)
{
    this->_framerateLimit = limit;
}

void arcade::api::Sdl2::display()
{
    SDL_RenderPresent(_renderer);
}

extern "C" arcade::api::Sdl2 *entryPoint()
{
    return arcade::api::Sdl2::getInstance();
}

arcade::api::Sdl2 *arcade::api::Sdl2::getInstance()
{
    if (_instance == nullptr)
        _instance = std::make_unique<Sdl2>();
    return _instance.get();
}
