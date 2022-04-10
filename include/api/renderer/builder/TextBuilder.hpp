/*
** EPITECH PROJECT, 2022
** TextBuilder.hpp
** File description:
** TextBuilder.hpp
*/

#ifndef ARCADE_TEXTBUILDER_HPP
#define ARCADE_TEXTBUILDER_HPP

#include "IBuilder.hpp"
#include "api/renderer/Text.hpp"

namespace arcade::api::renderer::builder {
    /**
     * @brief A builder for Text
     */
    class TextBuilder : public IBuilder<Text> {
    public:
        /**
         * @brief Construct a new Text Builder object
         * @attention Only some variables are set by default
         */
        TextBuilder() : _text("", "", ArcadeColor::White)
        {
            this->setPosition(0, 0);
            this->setScale(1, 1);
            this->setOrigin(0, 0);
            this->setRotation(0);
            this->setColor(ArcadeColor::White);
            this->setHighlighted(false);
            this->setHighlightColor(ArcadeColor::White);
            this->setTextPosition(TextPosition::LEFT);
        }

        /**
         * @brief Set the text position
         * @param pos the position
         * @return itself
         */
        TextBuilder &setPosition(const Vector2f &pos)
        {
            this->_text.setPosition(pos);
            return *this;
        }

        /**
         * @brief Set the text position
         * @param x The x position
         * @param y The y position
         * @return itself
         */
        TextBuilder &setPosition(float x, float y)
        {
            this->_text.setPosition(x, y);
            return *this;
        }

        /**
         * @brief Set the text rotation
         * @param rotation The rotation of the text in degrees
         * @return itself
         */
        TextBuilder &setRotation(float rotation)
        {
            this->_text.setRotation(rotation);
            return *this;
        }

        /**
         * @brief Set the text scale
         * @param scale The scale of the text
         * @return itself
         */
        TextBuilder &setScale(const Vector2f &scale)
        {
            this->_text.setScale(scale);
            return *this;
        }

        /**
         * @brief Set the text scale
         * @param factorX The scale factor on the X axis
         * @param factorY The scale factor on the Y axis
         * @return itself
         */
        TextBuilder &setScale(float factorX, float factorY)
        {
            this->_text.setScale(factorX, factorY);
            return *this;
        }

        /**
         * @brief Set the text origin
         * @param origin the origin
         * @return itself
         */
        TextBuilder &setOrigin(const Vector2f &origin)
        {
            this->_text.setOrigin(origin);
            return *this;
        }

        /**
         * @brief Set the text origin
         * @param x the x origin
         * @param y the y origin
         * @return itself
         */
        TextBuilder &setOrigin(float x, float y)
        {
            this->_text.setOrigin(x, y);
            return *this;
        }

        /**
         * @brief Set the text content
         * @param text the new text content
         * @return itself
         */
        TextBuilder &setText(const std::string &text)
        {
            this->_text.setText(text);
            return *this;
        }

        /**
         * @brief Set the fontPath
         * @param fontPath the new font path
         * @return itself
         */
        TextBuilder &setFontPath(const std::string &fontPath)
        {
            this->_text.setFontPath(fontPath);
            return *this;
        }

        /**
         * @brief Set the text color
         * @param color the new color
         * @return itself
         */
        TextBuilder &setColor(const Color &color)
        {
            this->_text.setColor(color);
            return *this;
        }

        /**
         * @brief Set the text highlighted
         * @param highlighted if the text is highlighted
         * @return itself
         */
        TextBuilder &setHighlighted(bool highlighted)
        {
            this->_text.setHightlighted(highlighted);
            return *this;
        }

        /**
         * @brief Set the text highlighted color
         * @param highlightColor the new color of the highlight
         * @return itself
         */
        TextBuilder &setHighlightColor(const Color &highlightColor)
        {
            this->_text.setHighlightColor(highlightColor);
            return *this;
        }

        /**
         * @brief Set the text position (automatically positionned)
         * @param textPosition the new text position
         * @return itself
         */
        TextBuilder &setTextPosition(TextPosition textPosition)
        {
            this->_text.setTextPosition(textPosition);
            return *this;
        }

        /**
         * @brief Build the text with all the variables
         * @return the built text
         * @throws ex::BuilderException when text and font path is empty
         */
        std::unique_ptr<Text> build() override
        {
            if (this->_text.getText().empty())
                throw ex::BuilderException("TextBuilder: text is empty");
            if (this->_text.getFontPath().empty())
                throw ex::BuilderException("TextBuilder: fontPath is empty");
            return std::make_unique<Text>(this->_text);
        }

    private:
        Text _text;
    };
}

using TextBuilder = arcade::api::renderer::builder::TextBuilder;

#endif //ARCADE_TEXTBUILDER_HPP
