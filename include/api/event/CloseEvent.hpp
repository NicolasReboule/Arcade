/*
** EPITECH PROJECT, 2022
** CloseEvent.hpp
** File description:
** CloseEvent.hpp
*/

#ifndef ARCADE_CLOSEEVENT_HPP
#define ARCADE_CLOSEEVENT_HPP

#include "IEvent.hpp"

namespace arcade::api::event {
    /**
     * @brief Triggered when the program need to exit
     */
    class CloseEvent : public IEvent {
    public:
        CloseEvent() = default;
    };
}

#endif //ARCADE_CLOSEEVENT_HPP
