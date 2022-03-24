/*
** EPITECH PROJECT, 2022
** AbstractSprite.hpp
** File description:
** AbstractSprite.hpp
*/

#ifndef ARCADE_ABSTRACTSPRITE_HPP
#define ARCADE_ABSTRACTSPRITE_HPP

#include "IDrawable.hpp"
#include "ITransformable.hpp"
#include <string>

namespace arcade::api::renderer {
    /**
     * @brief Base sprite class (will need to be recreate for each library)
     */
    class AbstractSprite : public IDrawable, public ITransformable {
    public:
        /**
         * @brief Constructor
         * @param texturePath the path of the texture
         * @param symbol the symbol (ncurses)
         */
        explicit AbstractSprite(const std::string &texturePath, const char symbol)
        {
            this->_texturePath = texturePath;
            this->_symbol = symbol;
        }

        ~AbstractSprite() override = default;

        /**
         * @brief Get the color of the sprite
         * @return the color of the sprite
         */
        const Color &getColor() const { return this->_color; }

        /**
         * @brief Set the color of the sprite
         * @param color the color to set
         */
        void setColor(const Color &color) { this->_color = color; }

        void draw(const IRenderTarget &target) override = 0;

        void setPosition(const Vector2f &pos) override = 0;
        void setPosition(int x, int y) override = 0;

        void setRotation(float rotation) override = 0;

        void setScale(const Vector2f &scale) override = 0;
        void setScale(float factorX, float factorY) override = 0;

        void setOrigin(const Vector2f &origin) override = 0;
        void setOrigin(float x, float y) override = 0;

        const Vector2f &getPosition() const override { return this->_position; }
        float getRotation() const override { return this->_rotation; }
        const Vector2f &getScale() const override {  return this->_scale; }
        const Vector2f &getOrigin() const override { return this->_origin; }

        void move(const Vector2f &offset) override = 0;
        void move(float offsetX, float offsetY) override = 0;

        void rotate(float angle) override = 0;

        void scale(const Vector2f &factor) override = 0;
        void scale(float factorX, float factorY) override = 0;

        /**
         * @brief Get the symbol of the sprite, used for ncurses
         * @param symbol the symbol to set
         */
        void setSymbol(char symbol) { this->_symbol = symbol; }

        /**
         * @brief Get the texturePath of the sprite
         * @param texturePath the texture path
         */
        void setTexturePath(const std::string &texturePath) { this->_texturePath = texturePath; }

    protected:
        std::string _texturePath;
        char _symbol;
        Vector2f _position;
        Vector2f _size;
        Vector2f _scale;
        Vector2f _origin;
        float _rotation;
        Color _color;
    };
}

#endif //ARCADE_ABSTRACTSPRITE_HPP
