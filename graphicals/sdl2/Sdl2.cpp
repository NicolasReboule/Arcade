/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Sdl2
*/

#include "Sdl2.hpp"

arcade::api::Sdl2::Sdl2(const std::string &name)
{
    _name = name;
}

extern "C" {

    void arcade::api::Sdl2::init()
    {
        if(SDL_Init(SDL_INIT_VIDEO) < 0) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
            exit(84);
        }
        if (SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &_window, &_renderer) < 0) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
            SDL_Quit();
        }
        _isOpen = true;
    }

    std::shared_ptr<arcade::api::Sdl2> entryPoint(void)
    {
        std::cout << "SDl2 entryPoint" << std::endl;
        std::shared_ptr<arcade::api::Sdl2> module = std::make_shared<arcade::api::Sdl2>("SDL2");
        return module;
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

    arcade::api::IDisplayModule *arcade::api::Sdl2::getInstance()
    {
        return NULL;
    }

    bool arcade::api::Sdl2::pollEvent(arcade::api::event::IEvent &events)
    {
        SDL_Event event;
        arcade::api::event::IEvent tmp;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:_isOpen = false;
                    break;
                // case SDL_KEYUP: events = arcade::api::event::
            }
        }
        return false;
    }
}
