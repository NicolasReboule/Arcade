/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Sdl2
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_

#include <SDL2/SDL.h>
#include "api/IDisplayModule.hpp"
#include "api/IGameModule.hpp"

namespace arcade::api
{
    class Sdl2 : public IDisplayModule {
        public:
            Sdl2();

            void init() override;
            void destroy() override;
            void display() override;
            void update() override;
            bool isOpen() const override;
            void clear() override;
            const std::string &getName() const override;
            inline LibraryType getType() const override { return DISPLAY;};
            static Sdl2 *getInstance();
            bool pollEvent(event::IEvent &event) override;

        private:
            library::ILibrary::LibraryType _type;
            std::string _name;
            SDL_Window *_window;
            SDL_Renderer *_renderer;
            static std::unique_ptr<Sdl2> _instance;
            bool _isOpen;
    };
}

#endif /* !SDL2_HPP_ */
