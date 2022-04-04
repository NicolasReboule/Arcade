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
         * @brief Constructor
         * @param texturePath the path of the texture
         * @param symbol the symbol (ncurses)
         */
        explicit Sprite(const std::string &texturePath, const char symbol) : AbstractDrawable()
        {
            this->_texturePath = texturePath;
            this->_symbol = symbol;
            this->_rotation = 0;
            this->_color = ArcadeColor::White;
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
         * @brief Get the symbol of the sprite, used for ncurses
         * @return the symbol of the sprite
         */
        char getSymbol() const { return this->_symbol; }

        /**
         * @brief Get the texturePath of the sprite
         * @return the texturePath of the sprite
         */
        const std::string &getTexturePath() const { return this->_texturePath; }

    protected:
        std::string _texturePath;
        char _symbol;
        Color _color;
    };
}

using Sprite = arcade::api::renderer::Sprite;

#endif //ARCADE_SPRITE_HPP
