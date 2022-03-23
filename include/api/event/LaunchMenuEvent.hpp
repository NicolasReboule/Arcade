/*
** EPITECH PROJECT, 2022
** LaunchMenuEvent.hpp
** File description:
** LaunchMenuEvent.hpp
*/

#ifndef ARCADE_LAUNCHMENUEVENT_HPP
#define ARCADE_LAUNCHMENUEVENT_HPP

#include "IEvent.hpp"

namespace arcade::api::event {
    /**
     * @brief Triggered when the need to go to the menu
     */
    class LaunchMenuEvent : public IEvent {
    public:
        LaunchMenuEvent() = default;
    };
}

#endif //ARCADE_LAUNCHMENUEVENT_HPP
