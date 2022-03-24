/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "api/IDisplayModule.hpp"
#include "api/event/Events.hpp"
#include <SFML/Graphics.hpp>

namespace arcade::api
{
    class Sfml : public IDisplayModule {
        public:
            Sfml();

            void init() override;
            void destroy() override;
            void display() override;
            void update() override;
            inline bool isOpen() const override {return _isOpen;};
            void clear() override;
            inline const std::string &getName() const override {return _name;};
            inline LibraryType getType() const override { return LibraryType::DISPLAY;};
            static Sfml *getInstance();
            bool pollEvent(event::IEvent &event) override;

        private:
            std::string _name;
            sf::RenderWindow _window;
            static std::unique_ptr<Sfml> _instance;
            bool _isOpen;
    };
}

#endif /* !SFML_HPP_ */
