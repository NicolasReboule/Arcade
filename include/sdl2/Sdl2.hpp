/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Sdl2
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_

#include <SDL2/SDL.h>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"

namespace arcade::api
{
    class Sdl2 : public IDisplayModule {
        public:
            explicit Sdl2(const std::string &name);

            void init() override;
            void destroy() override;
            void display() override;
            void update() override;
            bool isOpen() const override;
            void clear() override;
            inline SDL_Window *getWindow() { return this->_window; };
            const std::string &getName() const override;
            IDisplayModule *getInstance() override;
            bool pollEvent(event::IEvent &event) override;
            std::shared_ptr<arcade::api::Sdl2> entryPoint(void);

        protected:
            std::string _name;
            SDL_Window *_window;
            bool _isOpen;
            std::shared_ptr<IGameModule> _game;
    };
}

#endif /* !SDL2_HPP_ */
