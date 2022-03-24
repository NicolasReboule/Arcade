/*
** EPITECH PROJECT, 2022
** Color.hpp
** File description:
** Color.hpp
*/

#ifndef ARCADE_COLOR_HPP
#define ARCADE_COLOR_HPP

#include <cstdint>

namespace arcade::api::renderer {
    /**
     * @brief Color class (rgba)
     */
    class Color {
    public:
        /**
         * @brief Default constructor
         * Constructs an opaque black color. It is equivalent to Color(0, 0, 0, 255)
         */
        Color()
        {
            this->red = this->green = this->blue = 0;
            this->alpha = 255;
        }

        /**
         * @brief Construct a new Color object
         * @param red Red component (in the range [0, 255])
         * @param green Green component (in the range [0, 255])
         * @param blue Blue component (in the range [0, 255])
         * @param alpha Alpha (opacity) component (in the range [0, 255])
         */
        explicit Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = 255)
        {
            this->red = red;
            this->green = green;
            this->blue = blue;
            this->alpha = alpha;
        }

        /**
         * @brief Construct the color from 32-bit unsigned integer
         * @param color Number containing the RGBA components (in that order)
         */
        explicit Color(std::uint32_t color)
        {
            this->red = (color >> 24) & 0xFF;
            this->green = (color >> 16) & 0xFF;
            this->blue = (color >> 8) & 0xFF;
            this->alpha = color & 0xFF;
        }

        /**
         * @brief Retrieve the color as a 32-bit unsigned integer
         * @return Color represented as a 32-bit unsigned integer
         */
        std::uint32_t toInteger() const
        {
            return (this->red << 24) | (this->green << 16) | (this->blue << 8) | this->alpha;
        }

        static const Color Black;       /**< Black predefined color */
        static const Color White;       /**< White predefined color */
        static const Color Red;         /**< Red predefined color */
        static const Color Green;       /**< Green predefined color */
        static const Color Blue;        /**< Blue predefined color */
        static const Color Yellow;      /**< Yellow predefined color */
        static const Color Magenta;     /**< Magenta predefined color */
        static const Color Cyan;        /**< Cyan predefined color */
        static const Color Transparent; /**< Transparent (black) predefined color */

    private:
        std::uint8_t red;
        std::uint8_t green;
        std::uint8_t blue;
        std::uint8_t alpha;
    };

    const Color Color::Black = Color(0, 0, 0);
    const Color Color::White = Color(255, 255, 255);
    const Color Color::Red = Color(255, 0, 0);
    const Color Color::Green = Color(0, 255, 0);
    const Color Color::Blue = Color(0, 0, 255);
    const Color Color::Yellow = Color(255, 255, 0);
    const Color Color::Magenta = Color(255, 0, 255);
    const Color Color::Cyan = Color(0, 255, 255);
    const Color Color::Transparent = Color(0, 0, 0, 0);
}

#endif //ARCADE_COLOR_HPP
