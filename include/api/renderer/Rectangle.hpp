/*
** EPITECH PROJECT, 2022
** Rectangle.hpp
** File description:
** Rectangle.hpp
*/

#ifndef ARCADE_RECTANGLE_HPP
#define ARCADE_RECTANGLE_HPP

#include "AbstractDrawable.hpp"
#include "ITransformable.hpp"
#include "Color.hpp"
#include <string>

namespace arcade::api::renderer {
    /**
     * @brief Base rectangle class (will need to be recreate for each library)
     * @attention You need to override all method from this class
     */
    class Rectangle : public AbstractDrawable {
    public:
        /**
         * @brief Construct a new Rectangle object
         * @param fillColor the fill color
         * @param borderColor the color of the border
         * @param size the size of the rectangle
         * @param filled if the rectangle is filled or not (default=false)
         */
        explicit Rectangle(const Color &fillColor, const Color &borderColor, const Vector2f &size, bool filled = false) : AbstractDrawable()
        {
            this->_fillColor = fillColor;
            this->_borderColor = borderColor;
            this->_filled = filled;
            this->_size = size;
        }

        ~Rectangle() override = default;

        /**
         * @brief Copy constructor used for builder
         * @param other the other rectangle to copy
         */
        Rectangle(const Rectangle &other) = default;

        /**
         * @brief Update the rectangle
         * @attention Needs to be implemented in child class
         * @param drawable the updated rectangle
         * @throws arcade::api::ex::DrawableException
         */
        void update(const IDrawable &drawable) override
        {
            (void) drawable;
            this->_lastUpdate = Time::getNanosecondsTime();
            throw ex::DrawableException("Rectangle::update() is not implemented");
        }

        /**
         * @brief Check if the rectangle is filled
         * @return if the rectangle is filled
         */
        bool isFilled() const { return this->_filled; }

        /**
         * @brief Set rectangle filled
         * @param filled if it's filled
         */
        virtual void setFilled(bool filled) { this->_filled = filled; }

        /**
        * @brief Get the fill color of the rectangle
        * @return the fill color of the rectangle
        */
        const Color &getFillColor() const { return this->_fillColor; }

        /**
         * @brief Set the fill color of the rectangle
         * @param color the new fill color
         */
        virtual void setFillColor(const Color &fillColor) { this->_fillColor = fillColor; }

        /**
         * @brief Get the border color of the rectangle
         * @return the border color of the rectangle
         */
        const Color &getBorderColor() const { return this->_borderColor; }

        /**
         * @brief Set the border color of the rectangle
         * @param color the new border color
         */
        virtual void setBorderColor(const Color &color) { this->_borderColor = color; }

    protected:
        bool _filled;
        Color _fillColor;
        Color _borderColor;
    };
}

using Rectangle = arcade::api::renderer::Rectangle;

#endif //ARCADE_RECTANGLE_HPP
