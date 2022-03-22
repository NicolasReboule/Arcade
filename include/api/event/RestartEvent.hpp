/*
** EPITECH PROJECT, 2022
** RestartEvent.hpp
** File description:
** RestartEvent.hpp
*/

#ifndef RESTARTEVENT_HPP_
#define RESTARTEVENT_HPP_

#include "IEvent.hpp"

namespace arcade::api::event {
    class RestartEvent : public IEvent {
        public:
            RestartEvent() = default;
            ~RestartEvent() = default;
    };
}

#endif /* !RESTARTEVENT_HPP_ */
