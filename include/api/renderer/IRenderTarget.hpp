/*
** EPITECH PROJECT, 2022
** RenderTarget.hpp
** File description:
** RenderTarget.hpp
*/

#ifndef ARCADE_IRENDERTARGET_HPP
#define ARCADE_IRENDERTARGET_HPP

#include "api/NonCopyable.hpp"
#include "IDrawable.hpp"
#include "Color.hpp"
#include "api/Vector.hpp"

namespace arcade::api::renderer {
    /**
     * @brief Base class for all render targets (window, ...)
     */
    class IRenderTarget : public NonCopyable {
    public:
        virtual ~IRenderTarget() = default;

        /**
         * @brief Clear the render target with a specific color
         * This function is usually called once every frame, to clear the previous contents of the target.
         * @param color Fill color to use to clear the render target
         */
        virtual void clear(const Color &color = Color::Black) = 0;

        /**
         * @brief Draw a IDrawable object on the render target
         * @param drawable Object to draw
         */
        virtual void draw(const IDrawable &drawable) = 0;

        /**
         * @brief Return the size of the rendering region of the target
         * @return Size in pixels
         */
        virtual Vector2u getSize() const = 0;

    };
}

#endif //ARCADE_IRENDERTARGET_HPP
