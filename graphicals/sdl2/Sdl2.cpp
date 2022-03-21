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
    void loop(SDL_Renderer *renderer)
    {
        SDL_Event events;
        bool is_open = true;

        while (is_open) {
            while (SDL_PollEvent(&events)) {
                switch (events.type) {
                    case SDL_QUIT:is_open = false;
                        break;
                }
            }
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
        }
    }

    void arcade::api::Sdl2::init()
    {
        if(SDL_Init(SDL_INIT_VIDEO) < 0) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        }
        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;
        if (SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &window, &renderer) < 0) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
            SDL_Quit();
        }
        loop(renderer);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    std::shared_ptr<arcade::api::Sdl2> arcade::api::Sdl2::entryPoint(void)
    {
        std::cout << "SDl2 entryPoint" << std::endl;
        std::shared_ptr<arcade::api::Sdl2> module = std::make_shared<arcade::api::Sdl2>("SDL2");
        return module;
    }

    void arcade::api::Sdl2::destroy()
    {
    }

    void arcade::api::Sdl2::display()
    {
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
    }

    arcade::api::IDisplayModule *arcade::api::Sdl2::getInstance()
    {
        return NULL;
    }

    bool arcade::api::Sdl2::pollEvent(arcade::api::event::IEvent &event)
    {
        return false;
    }
}
