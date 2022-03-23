/*
** EPITECH PROJECT, 2022
** Vector.hpp
** File description:
** Vector.hpp
*/

#ifndef ARCADE_VECTOR_HPP
#define ARCADE_VECTOR_HPP

namespace arcade::api {
    /**
     * @brief Struct containing a vector with 2 dimensions
     * @tparam T the type of the vector
     */
    template <typename T>
    struct Vector2 final
    {
        T x;
        T y;
    };

    /**
     * @brief Struct containing a vector with 3 dimensions
     * @tparam T the type of the vector
     */
    template <typename T>
    struct Vector3 final
    {
        T x;
        T y;
        T z;
    };

    using Vector2i = Vector2<int>;
    using Vector2f = Vector2<float>;
    using Vector2u = Vector2<unsigned>;

    using Vector3i = Vector3<int>;
    using Vector3f = Vector3<float>;
    using Vector3u = Vector3<unsigned>;
}

#endif //ARCADE_VECTOR_HPP
