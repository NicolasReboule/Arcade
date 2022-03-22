/*
** EPITECH PROJECT, 2022
** CloseEvent.hpp
** File description:
** CloseEvent.hpp
*/

#ifndef CLOSEEVENT_HPP_
#define CLOSEEVENT_HPP_

#include "IEvent.hpp"

namespace arcade::api::event {
    class CloseEvent : public IEvent {
        public:
            CloseEvent() = default;
            ~CloseEvent() = default;
    };
}

#endif /* !CLOSEEVENT_HPP_ */
