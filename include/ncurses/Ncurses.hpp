/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "api/AbstractDisplayModule.hpp"
#include "ncurses.h"

namespace arcade::api {
    class NCurses : public AbstractDisplayModule {
    public:
        NCurses();

        static NCurses *getInstance();

        void init() override;

        void destroy() override;

        void close() override;

        void clear(const renderer::Color &color) override;

        void draw(const renderer::IDrawable &drawable) override;

        void createWindow(Vector2u size, const std::string &title) override;

        bool isOpen() const override;

        bool pollEvent(std::unique_ptr<event::IEvent> &event) override;

        void setSize(Vector2u size) override;

        void setTitle(const std::string &title) override;

        void setIcon(const std::string &path) override;

        void setFramerateLimit(uint limit) override;

        void display() override;

        void reset() override;

    private:
        static std::unique_ptr <NCurses> _instance;
    };
}
#endif /* !NCURSES_HPP_ */