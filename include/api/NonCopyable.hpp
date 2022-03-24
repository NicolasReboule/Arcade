/*
** EPITECH PROJECT, 2022
** NonCopyable.hpp
** File description:
** NonCopyable.hpp
*/

#ifndef ARCADE_NONCOPYABLE_HPP
#define ARCADE_NONCOPYABLE_HPP

namespace arcade {
    /**
     * @brief A non copyable class
     */
    class NonCopyable {
    public:
        NonCopyable() = default;
        ~NonCopyable() = default;

        /**
        * @brief Remove the copy constructor
        */
        NonCopyable(const NonCopyable &) = delete;

        /**
         * @brief Remove the copy constructor
         * @return nothing
         */
        NonCopyable &operator=(const NonCopyable &) = delete;
    };
}

#endif //ARCADE_NONCOPYABLE_HPP
