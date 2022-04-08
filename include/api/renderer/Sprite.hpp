/*
** EPITECH PROJECT, 2022
** Sprite.hpp
** File description:
** Sprite.hpp
*/

#ifndef ARCADE_SPRITE_HPP
#define ARCADE_SPRITE_HPP

#include "AbstractDrawable.hpp"
#include "Color.hpp"
#include <string>

namespace arcade::api::renderer {
    /**
     * @brief Base sprite class (will need to be recreate for each library)
     * @attention You need to override all method from this class
     */
    class Sprite : public AbstractDrawable {
    public:
        /**
         * @brief The flip type possibility
         */
        enum FlipType {
            NONE, /**< No flip */
            HORIZONTAL, /**< Horizontal flip */
            VERTICAL /**< Vertical flip */
        };

        /**
         * @brief Constructor
         * @param texturePath the path of the texture
         * @param symbol the symbol (ncurses)
         */
        explicit Sprite(const std::string &texturePath, const char symbol) : AbstractDrawable(), _textureOffset({0, 0})
        {
            this->_texturePath = texturePath;
            this->_symbol = symbol;
            this->_rotation = 0;
            this->_color = ArcadeColor::White;
            this->_flipType = FlipType::NONE;
        }

        ~Sprite() override = default;

        /**
         * @brief Update the sprite
         * @attention Needs to be implemented in child class
         * @param drawable the updated sprite
         * @throws arcade::api::ex::DrawableException
         */
        void update(const IDrawable &drawable) override
        {
            (void) drawable;
            this->_lastUpdate = Time::getNanosecondsTime();
            throw ex::DrawableException("Sprite::update() is not implemented");
        }

        /**
         * @brief Get the color of the sprite
         * @return the color of the sprite
         */
        const Color &getColor() const { return this->_color; }

        /**
         * @brief Set the color of the sprite
         * @param color the color to set
         */
        virtual void setColor(const Color &color) { this->_color = color; }

        /**
         * @brief Get the symbol of the sprite, used for ncurses
         * @param symbol the symbol to set
         */
        void setSymbol(char symbol) { this->_symbol = symbol; }

        /**
         * @brief Get the texturePath of the sprite
         * @param texturePath the texture path
         */
        virtual void setTexturePath(const std::string &texturePath) { this->_texturePath = texturePath; }

        /**
         * @brief Set the flip type @see FlipType
         * @param flipType
         */
        virtual void setFlipType(const FlipType &flipType) { this->_flipType = flipType; }

        /**
         * @brief Set the offset of the texture (like setTextureRect in SFML)
         * @param offset the offset
         */
        virtual void setTextureOffset(const Vector2i &offset) { this->_textureOffset = offset; }

        /**
         * @brief Get the symbol of the sprite, used for ncurses
         * @return the symbol of the sprite
         */
        char getSymbol() const { return this->_symbol; }

        /**
         * @brief Get the texturePath of the sprite
         * @return the texturePath of the sprite
         */
        const std::string &getTexturePath() const { return this->_texturePath; }

        /**
         * @brief Get the flip type @see FlipType
         * @return the flip type
         */
        FlipType getFlipType() const { return this->_flipType; }

        /**
         * @brief Get the texture offset
         * @return the texture offset
         */
        const Vector2i &getTextureOffset() const { return this->_textureOffset; }

    protected:
        std::string _texturePath;
        char _symbol;
        Color _color;
        FlipType _flipType;
        Vector2i _textureOffset;
    };
}

using Sprite = arcade::api::renderer::Sprite;
using FlipType = arcade::api::renderer::Sprite::FlipType;

#endif //ARCADE_SPRITE_HPP
