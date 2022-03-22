/*
** EPITECH PROJECT, 2022
** LaunchMenuEvent.hpp
** File description:
** LaunchMenuEvent.hpp
*/

#ifndef LAUNCHMENUEVENT_HPP_
#define LAUNCHMENUEVENT_HPP_

#include "IEvent.hpp"

namespace arcade::api::event {
    class LaunchMenuEvent : public IEvent {
        public:
            LaunchMenuEvent() = default;
            ~LaunchMenuEvent() = default;
    };
}

#endif /* !LAUNCHMENUEVENT_HPP_ */
