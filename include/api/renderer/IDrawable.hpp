/*
** EPITECH PROJECT, 2022
** IDrawable.hpp
** File description:
** IDrawable.hpp
*/

#ifndef ARCADE_IDRAWABLE_HPP
#define ARCADE_IDRAWABLE_HPP

#include "IRenderTarget.hpp"

namespace arcade::api::renderer {
    /**
     * @brief base class for objects that can be drawn to a render target
     */
    class IDrawable {
    public:
        virtual ~IDrawable() = default;

        /**
         * @brief Update the component
         * @attention Needs to be implemented in children graphicals library to update the component
         * @param drawable The drawable already updated
         */
        virtual void update(const IDrawable &drawable) = 0;

        /**
         * @brief Return the timestamp of the last use of this component
         * @return the timestamp of the last use of this component
         * @see std::chrono (nanoseconds)
         */
        virtual long getLastUpdate() const = 0;

        /**
         * @brief Get the id of the drawable
         * @return the id (sha1 hash)
         */
        virtual const std::string &getId() const = 0;
    };
}

#endif //ARCADE_IDRAWABLE_HPP
