/*
** EPITECH PROJECT, 2022
** IDrawable.hpp
** File description:
** IDrawable.hpp
*/

#ifndef ARCADE_IDRAWABLE_HPP
#define ARCADE_IDRAWABLE_HPP

namespace arcade::api::renderer {
    class IRenderTarget;
    /**
     * @brief base class for objects that can be drawn to a render target
     */
    class IDrawable {
    public:
        virtual ~IDrawable() = default;

    protected:
        /**
         * @brief Draw the object on the render target
         * This is a pure virtual function that has to be implemented
         * by the derived class to define how the drawable should be drown.
         * @param target Render target to draw to
         */
        virtual void draw(const IRenderTarget &target) = 0;
    };
}

#endif //ARCADE_IDRAWABLE_HPP
