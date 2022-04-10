/*
** EPITECH PROJECT, 2022
** SpriteBuilder.hpp
** File description:
** SpriteBuilder.hpp
*/

#ifndef ARCADE_SPRITEBUILDER_HPP
#define ARCADE_SPRITEBUILDER_HPP

#include "IBuilder.hpp"
#include "api/renderer/Sprite.hpp"

namespace arcade::api::renderer::builder {
    /**
     * @brief A builder for Sprite
     */
    class SpriteBuilder : public IBuilder<Sprite> {
    public:
        /**
         * @brief Construct a new Sprite Builder object
         * @attention Only some variables are set by default
         */
        SpriteBuilder() : _sprite("", -1)
        {
            this->_sprite.setRotation(0);
            this->_sprite.setColor(ArcadeColor::White);
            this->_sprite.setFlipType(FlipType::NONE);
            this->_sprite.setTextureOffset({0, 0});
        }

        /**
         * @brief Set the sprite position
         * @param pos the position
         * @return itself
         */
        SpriteBuilder &setPosition(const Vector2f &pos)
        {
            this->_sprite.setPosition(pos);
            return *this;
        }

        /**
         * @brief Set the sprite position
         * @param x The x position
         * @param y The y position
         * @return itself
         */
        SpriteBuilder &setPosition(float x, float y)
        {
            this->_sprite.setPosition(x, y);
            return *this;
        }

        /**
         * @brief Set the sprite rotation
         * @param rotation The rotation of the sprite in degrees
         * @return itself
         */
        SpriteBuilder &setRotation(float rotation)
        {
            this->_sprite.setRotation(rotation);
            return *this;
        }

        /**
         * @brief Set the sprite scale
         * @param scale The scale of the sprite
         * @return itself
         */
        SpriteBuilder &setScale(const Vector2f &scale)
        {
            this->_sprite.setScale(scale);
            return *this;
        }

        /**
         * @brief Set the sprite scale
         * @param factorX The scale factor on the X axis
         * @param factorY The scale factor on the Y axis
         * @return itself
         */
        SpriteBuilder &setScale(float factorX, float factorY)
        {
            this->_sprite.setScale(factorX, factorY);
            return *this;
        }

        /**
         * @brief Set the sprite origin
         * @param origin the origin
         * @return itself
         */
        SpriteBuilder &setOrigin(const Vector2f &origin)
        {
            this->_sprite.setOrigin(origin);
            return *this;
        }

        /**
         * @brief Set the sprite origin
         * @param x the x origin
         * @param y the y origin
         * @return itself
         */
        SpriteBuilder &setOrigin(float x, float y)
        {
            this->_sprite.setOrigin(x, y);
            return *this;
        }

        /**
         * @brief Set the sprite color (tty only)
         * @param color the new color
         * @return itself
         */
        SpriteBuilder &setColor(const Color &color)
        {
            this->_sprite.setColor(color);
            return *this;
        }

        /**
         * @brief Set the sprite symbol (for tty library)
         * @param symbol the new symbol
         * @return itself
         */
        SpriteBuilder &setSymbol(char symbol)
        {
            this->_sprite.setSymbol(symbol);
            return *this;
        }

        /**
         * @brief Set the sprite texture path
         * @param texturePath the new texture path
         * @return itself
         */
        SpriteBuilder &setTexturePath(const std::string &texturePath)
        {
            this->_sprite.setTexturePath(texturePath);
            return *this;
        }

        /**
         * @brief Set the sprite flip type
         * @param flipType the new flip type
         * @return itself
         */
        SpriteBuilder &setFlipType(const FlipType &flipType)
        {
            this->_sprite.setFlipType(flipType);
            return *this;
        }

        /**
         * @brief Set the offset of the texture
         * @param textureOffset the texture offset
         * @return itself
         */
        SpriteBuilder &setTextureOffset(const Vector2i &offset)
        {
            this->_sprite.setTextureOffset(offset);
            return *this;
        }

        std::unique_ptr<Sprite> build() override
        {
            if (this->_sprite.getTexturePath().empty())
                throw ex::BuilderException("SpriteBuilder: texture path is empty");
            if (this->_sprite.getSymbol() == -1)
                throw ex::BuilderException("SpriteBuilder: symbol is not set");
            return std::make_unique<Sprite>(this->_sprite);
        }

    private:
        Sprite _sprite;
    };
}

using SpriteBuilder = arcade::api::renderer::builder::SpriteBuilder;

#endif //ARCADE_SPRITEBUILDER_HPP
