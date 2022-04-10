/*
** EPITECH PROJECT, 2022
** IBuilder.hpp
** File description:
** IBuilder.hpp
*/

#ifndef ARCADE_IBUILDER_HPP
#define ARCADE_IBUILDER_HPP

#include <memory>

namespace arcade::api::renderer::builder {
    /**
     * @brief Interface for all the builder
     * @tparam T the class to build
     */
    template<typename T>
    class IBuilder {
    public:
        /**
         * @brief Will return an instance of the templated parameter
         * @tparam The class to build
         * @return a unique_ptr of the templated parameter
         * @attention Can throw some errors
         */
        virtual std::unique_ptr<T> build() = 0;
    };
}

#endif //ARCADE_IBUILDER_HPP
