/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Sdl2
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_

#include <SDL2/SDL.h>
#include <api/window/Keyboard.hpp>
#include "api/AbstractDisplayModule.hpp"
#include "api/IGameModule.hpp"

namespace arcade::api {
    class Sdl2 : public AbstractDisplayModule {
    public:
        Sdl2();

        void reset() override;

        static Sdl2 *getInstance();

        void init() override;

        void destroy() override;

        void close() override;

        void clear(const renderer::Color &color) override;

        void draw(const renderer::IDrawable &drawable) override;

        void createWindow(Vector2u size, const std::string &title) override;

        bool isOpen() const override;

        bool pollEvent(std::unique_ptr<ArcadeEvent> &event) override;

        void setSize(Vector2u size) override;

        void setTitle(const std::string &title) override;

        void setIcon(const std::string &path) override;

        void setFramerateLimit(uint limit) override;

        void display() override;

    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        std::unordered_map<SDL_Keycode, KeyCode> _keyMap;
        static std::unique_ptr<Sdl2> _instance;
    };
}

#endif /* !SDL2_HPP_ */
