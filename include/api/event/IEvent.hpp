/*
** EPITECH PROJECT, 2022
** IEvent.hpp
** File description:
** IEvent.hpp
*/

#ifndef ARCADE_IEVENT_HPP
#define ARCADE_IEVENT_HPP

#include <iostream>

namespace arcade::api::event {
    /**
     * @brief Interface for all events
     */
    class IEvent {
    public:
        IEvent() = default;
        virtual ~IEvent() = default;
    };
}

#endif //ARCADE_IEVENT_HPP
