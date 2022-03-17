/*
** EPITECH PROJECT, 2022
** Vector.hpp
** File description:
** Vector.hpp
*/

#ifndef ARCADE_VECTOR_HPP
#define ARCADE_VECTOR_HPP

namespace arcade::api {
    template<typename T>
    class Vector {
        explicit Vector(T x, T y) : _x(x), _y(y) {};

        virtual void setX(T x) = 0;
        virtual void  setY(T y) = 0;
        virtual T getX() const = 0;
        virtual T getY() const = 0;

    private:
        T _x;
        T _y;
    };
}

#endif //ARCADE_VECTOR_HPP
