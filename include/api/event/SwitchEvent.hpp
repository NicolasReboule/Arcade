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
        inline SwitchType getType()
        {
            return this->_type;
        }

        /**
         * Get the direction of the switch
         * @return the direction of the switch
         */
        inline SwitchDirection getDirection()
        {
            return this->_direction;
        }

    private:
        SwitchType _type; /**< The switch type */
        SwitchDirection _direction; /**< The direction */
    };
}

#endif //ARCADE_SWITCHEVENT_HPP
