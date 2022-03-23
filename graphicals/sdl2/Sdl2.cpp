/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Sdl2
*/

#include "Sdl2.hpp"
#include "SwitchEvent.hpp"

std::unique_ptr<arcade::api::Sdl2> arcade::api::Sdl2::_instance;

arcade::api::Sdl2::Sdl2()
{
    _name = "Sdl2";
}

void arcade::api::Sdl2::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        exit(84);
    }
    if (SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &_window, &_renderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        SDL_Quit();
    }
    _isOpen = true;
}

extern "C" arcade::api::Sdl2 *entryPoint()
{
    return arcade::api::Sdl2::getInstance();
}

void arcade::api::Sdl2::destroy()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void arcade::api::Sdl2::display()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
}

void arcade::api::Sdl2::update()
{
}

const std::string &arcade::api::Sdl2::getName() const
{
    return _name;
}

bool arcade::api::Sdl2::isOpen() const
{
    return this->_isOpen;
}

void arcade::api::Sdl2::clear()
{
    SDL_RenderClear(_renderer);
    SDL_RenderPresent(_renderer);
}

arcade::api::Sdl2 *arcade::api::Sdl2::getInstance()
{
    if (_instance == nullptr)
        _instance = std::make_unique<Sdl2>();
    return _instance.get();
}

bool arcade::api::Sdl2::pollEvent(arcade::api::event::IEvent &events)
{
    SDL_Event event;
    arcade::api::event::IEvent tmp;
    while (SDL_PollEvent(&event))
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            _isOpen = false;
            break;
        case SDLK_UP:
            events = event::SwitchEvent(event::SwitchEvent::GAME, event::SwitchEvent::NEXT);
            std::cout << "azertfgdfdfghgfsfg"
                      << "\n";
            break;
        }
    }
    return false;
}
