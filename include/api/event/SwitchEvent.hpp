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

        /**
         * @brief Check if the type of the switch is a game
         * @return true if the switch type is a game, false otherwise
         */
        inline bool isGame() const noexcept
        {
            return this->_type == SwitchType::GAME;
        }

        /**
         * @brief Check if the type of the switch is a display
         * @return true if the switch type is a display, false otherwise
         */
        inline bool isDisplay() const noexcept
        {
            return this->_type == SwitchType::DISPLAY;
        }

        /**
         * @brief Check if the direction of the switch is previous
         * @return true if the switch direction is previous, false otherwise
         */
        inline bool isPrevious() const noexcept
        {
            return this->_direction == SwitchDirection::PREV;
        }

        /**
         * @brief Check if the direction of the switch is next
         * @return true if the switch direction is next, false otherwise
         */
        inline bool isNext() const noexcept
        {
            return this->_direction == SwitchDirection::NEXT;
        }

    private:
        SwitchType _type; /**< The switch type */
        SwitchDirection _direction; /**< The direction */
    };
}

using SwitchEvent = arcade::api::event::SwitchEvent;
using SwitchType = arcade::api::event::SwitchEvent::SwitchType;
using SwitchDirection = arcade::api::event::SwitchEvent::SwitchDirection;

/**
 * @brief Return the opposite direction
 * @param direction the actual direction
 * @return the opposite direction
 */
inline SwitchDirection operator!(const SwitchDirection &direction)
{
    return direction == SwitchDirection::PREV ? SwitchDirection::NEXT
                                              : SwitchDirection::PREV;
}

/**
 * @brief Return the opposite type
 * @param type the actual type
 * @return the opposite type
 */
inline SwitchType operator!(const SwitchType &type)
{
    return type == SwitchType::GAME ? SwitchType::DISPLAY : SwitchType::GAME;
}

/**
 * @brief Show the SwitchType in ostream
 * @param os the ostream
 * @param type the switch type
 * @return the ostream with the switch type
 */
inline std::ostream &operator<<(std::ostream &os, const SwitchType &type)
{
    os << "SwitchType: ";
    if (type == SwitchType::DISPLAY)
        os << "DISPLAY";
    else
        os << "GAME";
    return os;
}

/**
 * @brief Show the SwitchDirection in ostream
 * @param os the ostream
 * @param direction the switch direction
 * @return the ostream with the switch direction
 */
inline std::ostream &
operator<<(std::ostream &os, const SwitchDirection &direction)
{
    os << "SwitchDirection: ";
    if (direction == SwitchEvent::SwitchDirection::PREV)
        os << "PREV";
    else
        os << "NEXT";
    return os;
}

/**
 * @brief Show the SwitchEvent in ostream
 * @param os the ostream
 * @param event the switch event
 * @return the ostream with the switch event
 */
inline std::ostream &operator<<(std::ostream &os, const SwitchEvent &event)
{
    os << "SwitchEvent: " << event.getType() << " " << event.getDirection();
    return os;
}

#endif //ARCADE_SWITCHEVENT_HPP
