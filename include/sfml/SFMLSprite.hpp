/*
** EPITECH PROJECT, 2022
** SFMLSprite.hpp
** File description:
** SFMLSprite.hpp
*/

#ifndef ARCADE_SFMLSPRITE_HPP
#define ARCADE_SFMLSPRITE_HPP

#include "api/renderer/Sprite.hpp"
#include <SFML/Graphics.hpp>

namespace arcade::sfml {
    class SFMLSprite : public api::renderer::Sprite {
    public:
        explicit SFMLSprite(const Sprite &sprite);

        void update(const IDrawable &drawable) override;

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

        void setColor(const api::renderer::Color &color) override;

        void setTexturePath(const std::string &texturePath) override;

        const sf::Sprite &getSprite() const;

    private:
        sf::Sprite _sprite;
        sf::Texture _texture;
    };
}

#endif //ARCADE_SFMLSPRITE_HPP
