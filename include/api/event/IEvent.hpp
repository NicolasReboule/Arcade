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
        explicit IEvent(std::string name = ""): _name(name){};
        virtual ~IEvent() = default;
        std::string _name;
    };
}

#endif //ARCADE_IEVENT_HPP
