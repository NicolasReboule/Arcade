/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "api/AbstractDisplayModule.hpp"
#include <SFML/Graphics.hpp>

namespace arcade::api {
    class Sfml : public AbstractDisplayModule {
    public:
        Sfml();

        static Sfml *getInstance();

        void init() override;

        void clear(const renderer::Color &color) override;

        void draw(const renderer::IDrawable &drawable) override;

        void createWindow(Vector2u size, const std::string &title) override;

        bool pollEvent(std::unique_ptr<event::IEvent> &event) override;

        void setSize(Vector2u size) override;

        void reset() override;

        void setTitle(const std::string &title) override;

        void setIcon(const std::string &path) override;

        void destroy() override;

        void setFramerateLimit(uint limit) override;

        void display() override;

        bool isOpen() const override;

        void close() override;

    private:
        sf::RenderWindow _window;
        static Sfml *_instance;
    };
}

#endif /* !SFML_HPP_ */
