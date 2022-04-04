/*
** EPITECH PROJECT, 2022
** SFMLText.hpp
** File description:
** SFMLText.hpp
*/

#ifndef ARCADE_SFMLTEXT_HPP
#define ARCADE_SFMLTEXT_HPP

#include "api/renderer/Text.hpp"
#include <SFML/Graphics.hpp>

namespace arcade::sfml {
    class SFMLText : public api::renderer::Text {
    public:
        explicit SFMLText(const Text &text);

        void update(const IDrawable &drawable) override;

        void setText(const std::string &text) override;

        void setFontPath(const std::string &fontPath) override;

        void setColor(const api::renderer::Color &color) override;

        void setHightlighted(bool highlighted) override;

        void setHighlightColor(const api::renderer::Color &color) override;

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

        const sf::Text &getSfText() const;
    private:
        sf::Text _text;
        sf::Font _font;
    };
}

#endif //ARCADE_SFMLTEXT_HPP
