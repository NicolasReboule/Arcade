/*
** EPITECH PROJECT, 2022
** RenderTarget.hpp
** File description:
** RenderTarget.hpp
*/

#ifndef ARCADE_IRENDERTARGET_HPP
#define ARCADE_IRENDERTARGET_HPP

#include "api/utils/NonCopyable.hpp"
#include "IDrawable.hpp"
#include "Color.hpp"
#include "api/utils/Vector.hpp"

namespace arcade::api::renderer {
    /**
     * @brief Base class for all render targets (window, ...)
     */
    class IRenderTarget : public utils::NonCopyable {
    public:
        virtual ~IRenderTarget() = default;

        /**
         * @brief Clear the render target with a specific color
         * This function is usually called once every frame, to clear the previous contents of the target.
         * @param color Fill color to use to clear the render target (default: Black)
         */
        virtual void clear(const Color &color = Color::Black) = 0;

        /**
         * @brief Draw a IDrawable object on the render target
         * @param drawable Object to draw
         */
        virtual void draw(const IDrawable &drawable) = 0;

    };
}

#endif //ARCADE_IRENDERTARGET_HPP
