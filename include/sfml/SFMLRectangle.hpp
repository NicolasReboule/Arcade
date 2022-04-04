/*
** EPITECH PROJECT, 2022
** SFMLRectangle.hpp
** File description:
** SFMLRectangle.hpp
*/

#ifndef ARCADE_SFMLRECTANGLE_HPP
#define ARCADE_SFMLRECTANGLE_HPP

#include "api/renderer/Rectangle.hpp"
#include <SFML/Graphics.hpp>

namespace arcade::sfml {
    class SFMLRectangle : public api::renderer::Rectangle {
    public:
        explicit SFMLRectangle(const Rectangle &rectangle);

        void update(const IDrawable &drawable) override;

        void setFillColor(const api::renderer::Color &color) override;

        void setBorderColor(const api::renderer::Color &color) override;

        void setPosition(const Vector2f &pos) override;

        void setPosition(float x, float y) override;

        void setRotation(float rotation) override;

        void setScale(const Vector2f &scale) override;

        void setScale(float factorX, float factorY) override;

        void setOrigin(const Vector2f &origin) override;

        void setOrigin(float x, float y) override;

        void move(const Vector2f &offset) override;

        void move(float offsetX, float offsetY) override;

        void rotate(float angle) override;

        void scale(const Vector2f &factor) override;

        void scale(float factorX, float factorY) override;

        void setSize(const Vector2f &size) override;

        const sf::RectangleShape &getShape();

    private:
        sf::RectangleShape _rectangle;
    };
}

#endif //ARCADE_SFMLRECTANGLE_HPP
