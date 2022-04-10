/*
** EPITECH PROJECT, 2022
** Text.hpp
** File description:
** Text.hpp
*/

#ifndef ARCADE_TEXT_HPP
#define ARCADE_TEXT_HPP

#include "AbstractDrawable.hpp"
#include "ITransformable.hpp"
#include "Color.hpp"
#include <string>

namespace arcade::api::renderer {
    /**
     * @brief Base text class (will need to be recreate for each library)
     * @attention You need to override all method from this class
     */
    class Text : public AbstractDrawable {
    public:
        /**
         * @brief The text position, will be used to automatically alignate the text with their current position
         */
        enum TextPosition {
            LEFT, /*< Left position (aka x: 0) */
            MIDDLE, /**< Middle position (aka x: width/2) */
            RIGHT /**< Right position (aka x: -width) */
        };

        explicit Text(const std::string &text, const std::string &fontPath, const Color &color) : AbstractDrawable()
        {
            this->_text = text;
            this->_fontPath = fontPath;
            this->_color = color;
            this->_highlightColor = Color::White;
            this->_rotation = 0;
            this->_highlighted = false;
            this->_textPosition = TextPosition::LEFT;
        }
        ~Text() override = default;

        /**
         * @brief Copy constructor used for builder
         * @param other the other text to copy
         */
        Text(const Text &other) = default;

        /**
          * @brief Update the text
          * @attention Needs to be implemented in child class
          * @param drawable the updated text
          * @throws arcade::api::ex::DrawableException
          */
        void update(const IDrawable &drawable) override
        {
            (void) drawable;
            this->_lastUpdate = Time::getNanosecondsTime();
            throw ex::DrawableException("Text::update() is not implemented");
        }

        /**
         * @brief Set the text
         * @param text the new text
         */
        virtual void setText(const std::string &text) { this->_text = text; }

        /**
         * @brief Set the font path
         * @param fontPath the new font path
         */
        virtual void setFontPath(const std::string &fontPath) { this->_fontPath = fontPath; }

        /**
         * @brief Set the color of the text
         * @param color the new color
         */
        virtual void setColor(const Color &color) { this->_color = color; }

        /**
         * @brief Set if the text is highlighted
         * @param highlighted if the text is highlighted
         */
        virtual void setHightlighted(bool highlighted) { this->_highlighted = highlighted; }

        /**
         * @brief Set the color of the highlight
         * @param color the new color of the highlight
         */
        virtual void setHighlightColor(const Color &color) { this->_highlightColor = color; }

        /**
         * @brief Set the text position, the origin will be modified
         * @param textPosition the new text position
         */
        virtual void setTextPosition(TextPosition textPosition) { this->_textPosition = textPosition; }

        /**
         * @brief Get the text
         * @return the text
         */
        const std::string &getText() const { return this->_text; }

        /**
         * @brief Get the font path
         * @return the font path
         */
        const std::string &getFontPath() const { return this->_fontPath; }

        /**
         * @brief Get the color of the text
         * @return the color of the text
         */
        const Color &getColor() const { return this->_color; }

        /**
         * @brief Check if the text is highlighted
         * @return if the text is highlighted
         */
        bool isHighlighted() const { return this->_highlighted; }

        /**
         * @brief Get the color of the highlight
         * @return the color of the highlight
         */
        const Color &getHighlightColor() const { return this->_highlightColor; }

        /**
         * @brief Get the TextPosition
         * @return the text position
         */
        TextPosition getTextPosition() const { return this->_textPosition; }

    private:
        std::string _text;
        std::string _fontPath;
        Color _color;
        bool _highlighted;
        Color _highlightColor;
        TextPosition _textPosition;
    };
}

using Text = arcade::api::renderer::Text;
using TextPosition = arcade::api::renderer::Text::TextPosition;

#endif //ARCADE_TEXT_HPP
