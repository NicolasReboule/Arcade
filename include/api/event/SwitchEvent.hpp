/*
** EPITECH PROJECT, 2021
** SwitchEvent.hpp
** File description:
** SwitchEvent.hpp
*/

#ifndef SWITCHEVENT_HPP_
#define SWITCHEVENT_HPP_

#include "IEvent.hpp"

namespace arcade::api::event {
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

            SwitchEvent(SwitchType type, SwitchDirection direction): _type(type), _direction(direction) {};
            ~SwitchEvent() = default;
            inline SwitchType getType() const {return _type;};
            inline SwitchDirection getDirection() const {return _direction;};

        private:
            SwitchType _type;
            SwitchDirection _direction;
    };
}

#endif /* !SWITCHEVENT_HPP_ */
