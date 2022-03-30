/*
** EPITECH PROJECT, 2021
** SwitchEvent.hpp
** File description:
** SwitchEvent.hpp
*/

#ifndef ARCADE_SWITCHEVENT_HPP
#define ARCADE_SWITCHEVENT_HPP

#include "IEvent.hpp"

namespace arcade::api::event {
    /**
     * @brief Triggered when game/display is switched
     */
    class SwitchEvent : public IEvent {
    public:
        enum SwitchType {
            GAME,
            DISPLAY
        };

        enum SwitchDirection {
            PREV,
            NEXT
        };

        /**
         * Constructor of SwitchEvent
         * @param type the type of switch
         * @param direction the direction of switch
         */
        explicit SwitchEvent(SwitchType type, SwitchDirection direction)
        {
            this->_type = type;
            this->_direction = direction;
        }

        /**
         * Get the type of the switch
         * @return the type of the switch
         */
        inline SwitchType getType() const noexcept
        {
            return this->_type;
        }

        /**
         * Get the direction of the switch
         * @return the direction of the switch
         */
        inline SwitchDirection getDirection() const noexcept
        {
            return this->_direction;
        }

    private:
        SwitchType _type; /**< The switch type */
        SwitchDirection _direction; /**< The direction */
    };
}

using SwitchEvent = arcade::api::event::SwitchEvent;
using SwitchType = arcade::api::event::SwitchEvent::SwitchType;
using SwitchDirection = arcade::api::event::SwitchEvent::SwitchDirection;

inline std::ostream &operator<<(std::ostream &os, const SwitchType &type)
{
    os << "SwitchType: ";
    if (type == SwitchType::DISPLAY)
        os << "DISPLAY";
    else
        os << "GAME";
    return os;
}

inline std::ostream &operator<<(std::ostream &os, const SwitchDirection &direction)
{
    os << "SwitchDirection: ";
    if (direction == SwitchEvent::SwitchDirection::PREV)
        os << "PREV";
    else
        os << "NEXT";
    return os;
}

inline std::ostream &operator<<(std::ostream &os, const SwitchEvent &event)
{
    os << "SwitchEvent: " << event.getType() << " " << event.getDirection();
    return os;
}

#endif //ARCADE_SWITCHEVENT_HPP
