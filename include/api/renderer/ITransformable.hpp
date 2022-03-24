/*
** EPITECH PROJECT, 2022
** ITransformable.hpp
** File description:
** ITransformable.hpp
*/

#ifndef ARCADE_ITRANSFORMABLE_HPP
#define ARCADE_ITRANSFORMABLE_HPP

#include "api/Vector.hpp"

namespace arcade::api::renderer {
    /**
     * @brief Will be used to place/rotate your Drawable object
     */
    class ITransformable {
    public:
        virtual ~ITransformable() = default;

        /**
         * @brief Set the position of the object
         * @param pos The position of the object
         */
        virtual void setPosition(const Vector2f &pos) = 0;

        /**
         * @brief Set the position of the object
         * @param x The x position
         * @param y The y position
         */
        virtual void setPosition(int x, int y) = 0;

        /**
         * @brief Set the rotation of the object
         * @param rotation The rotation of the object in degrees
         */
        virtual void setRotation(float rotation) = 0;

        /**
         * @brief Set the scale of the object
         * @param scale The scale of the object
         */
        virtual void setScale(const Vector2f &scale) = 0;

        /**
         * @brief Set the scale of the object
         * @param factorX The scale factor on the X axis
         * @param factorY The scale factor on the Y axis
         */
        virtual void setScale(float factorX, float factorY) = 0;

        /**
         * @brief Set the origin of the object
         * @param origin the origin
         */
        virtual void setOrigin(const Vector2f &origin) = 0;

        /**
         * @brief Set the origin of the object
         * @param x the x origin
         * @param y the y origin
         */
        virtual void setOrigin(float x, float y) = 0;

        /**
         * @brief Get the position of the object
         * @return the position of the object
         */
        virtual const Vector2f &getPosition() const = 0;

        /**
         * @brief Get the rotation of the object
         * @return the rotation of the object
         */
        virtual float getRotation() const = 0;

        /**
         * @brief Get the scale of the object
         * @return the scale of the object
         */
        virtual const Vector2f& getScale() const = 0;

        /**
         * @brief Get the origin of the object
         * @return the origin of the object
         */
        virtual const Vector2f& getOrigin() const = 0;

        /**
         * @brief Move the object by a given offset
         * @param offset Offset
         * @see move(float, float)
         */
        virtual void move(const Vector2f &offset) = 0;

        /**
         * @brief Move the object by a given offset
         * This function adds to the current position of the object, unlike setPosition which overwrites it.
         * Thus, it is equivalent to the following code:
         * @code
         * Vector2f pos = object.getPosition();
         * object.setPosition(pos.x + offsetX, pos.y + offsetY);
         * @param offsetX X offset
         * @param offsetY Y offset
         */
        virtual void move(float offsetX, float offsetY) = 0;

        /**
         * @brief Rotate the object
         * This function adds to the current rotation of the object, unlike setRotation which overwrites it.
         * Thus, it is equivalent to the following code:
         * @code object.setRotation(object.getRotation() + angle); @endcode
         * @param angle Angle of rotation, in degrees
         */
        virtual void rotate(float angle) = 0;

        /**
         * @brief Scale the object
         * @see scale(float, float)
         * @param factor
         */
        virtual void scale(const Vector2f& factor) = 0;

        /**
         * @brief Scale the object in x and y axis
         * This function multiplies the current scale of the object, unlike setScale which overwrites it.
         * Thus, it is equivalent to the following code:
         * @code
         * Vector2f scale = object.getScale();
         * object.setScale(scale.x * factorX, scale.y * factorY);
         * @endcode
         * @param factorX Horizontal scale factor
         * @param factorY Vertical scale factor
         * @see setScale
         */
        virtual void scale(float factorX, float factorY) = 0;
    };
}

#endif //ARCADE_ITRANSFORMABLE_HPP
