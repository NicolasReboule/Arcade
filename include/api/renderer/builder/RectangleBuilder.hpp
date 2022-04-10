/*
** EPITECH PROJECT, 2022
** RectangleBuilder.hpp
** File description:
** RectangleBuilder.hpp
*/

#ifndef ARCADE_RECTANGLEBUILDER_HPP
#define ARCADE_RECTANGLEBUILDER_HPP

#include "IBuilder.hpp"
#include "api/renderer/Rectangle.hpp"

namespace arcade::api::renderer::builder {
    /**
     * @brief A builder for Rectangle
     */
    class RectangleBuilder : public IBuilder<Rectangle> {
    public:
        /**
         * @brief Construct a new Rectangle Builder object
         * @attention Only some variables are set by default
         */
        RectangleBuilder() : _rectangle(ArcadeColor::White, ArcadeColor::White, {0, 0})
        {
            this->setPosition(0, 0);
            this->setScale(1, 1);
            this->setOrigin(0, 0);
            this->setRotation(0);
            this->setSize({0, 0});
            this->setFilled(false);
            this->setFillColor(ArcadeColor::White);
            this->setBorderColor(ArcadeColor::White);
        }

        /**
         * @brief Set the rectangle position
         * @param pos the position
         * @return itself
         */
        RectangleBuilder &setPosition(const Vector2f &pos)
        {
            this->_rectangle.setPosition(pos);
            return *this;
        }

        /**
         * @brief Set the rectangle position
         * @param x The x position
         * @param y The y position
         * @return itself
         */
        RectangleBuilder &setPosition(float x, float y)
        {
            this->_rectangle.setPosition(x, y);
            return *this;
        }

        /**
         * @brief Set the rectangle rotation
         * @param rotation The rotation of the rectangle in degrees
         * @return itself
         */
        RectangleBuilder &setRotation(float rotation)
        {
            this->_rectangle.setRotation(rotation);
            return *this;
        }

        /**
         * @brief Set the rectangle scale
         * @param scale The scale of the rectangle
         * @return itself
         */
        RectangleBuilder &setScale(const Vector2f &scale)
        {
            this->_rectangle.setScale(scale);
            return *this;
        }

        /**
         * @brief Set the rectangle scale
         * @param factorX The scale factor on the X axis
         * @param factorY The scale factor on the Y axis
         * @return itself
         */
        RectangleBuilder &setScale(float factorX, float factorY)
        {
            this->_rectangle.setScale(factorX, factorY);
            return *this;
        }

        /**
         * @brief Set the rectangle origin
         * @param origin the origin
         * @return itself
         */
        RectangleBuilder &setOrigin(const Vector2f &origin)
        {
            this->_rectangle.setOrigin(origin);
            return *this;
        }

        /**
         * @brief Set the rectangle origin
         * @param x the x origin
         * @param y the y origin
         * @return itself
         */
        RectangleBuilder &setOrigin(float x, float y)
        {
            this->_rectangle.setOrigin(x, y);
            return *this;
        }

        /**
         * @brief Set the rectangle size
         * @param size the new rectangle size
         * @return itself
         */
        RectangleBuilder &setSize(const Vector2f &size)
        {
            this->_rectangle.setSize(size);
            return *this;
        }

        /**
         * @brief Set the rectangle filled
         * @param filled if it's filled
         * @return itself
         */
        RectangleBuilder &setFilled(bool filled)
        {
            this->_rectangle.setFilled(filled);
            return *this;
        }

        /**
         * @brief Set the rectangle filled color
         * @param fillColor the new fill color
         * @return itself
         */
        RectangleBuilder &setFillColor(const Color &fillColor)
        {
            this->_rectangle.setFillColor(fillColor);
            return *this;
        }

        /**
         * @brief Set the rectangle border color
         * @param color the new border color
         * @return itself
         */
        RectangleBuilder &setBorderColor(const Color &color)
        {
            this->_rectangle.setBorderColor(color);
            return *this;
        }

        /**
         * @brief Build the rectangle with all the variables
         * @return the built rectangle
         */
        std::unique_ptr<Rectangle> build() override
        {
            return std::make_unique<Rectangle>(this->_rectangle);
        }

    private:
        Rectangle _rectangle;
    };
}

using RectangleBuilder = arcade::api::renderer::builder::RectangleBuilder;

#endif //ARCADE_RECTANGLEBUILDER_HPP
