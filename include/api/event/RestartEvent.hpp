/*
** EPITECH PROJECT, 2022
** RestartEvent.hpp
** File description:
** RestartEvent.hpp
*/

#ifndef ARCADE_RESTARTEVENT_HPP
#define ARCADE_RESTARTEVENT_HPP

#include "IEvent.hpp"

namespace arcade::api::event {
    /**
     * @brief Triggered when the game is restarted
     */
    class RestartEvent : public IEvent {
    public:
        RestartEvent() = default;
    };
}

inline std::ostream &operator<<(std::ostream &os, const arcade::api::event::RestartEvent &restartEvent)
{
    (void) restartEvent;
    return os << "RestartEvent";
}


#endif //ARCADE_RESTARTEVENT_HPP
