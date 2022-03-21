/*
** EPITECH PROJECT, 2022
** KeyEvent.hpp
** File description:
** KeyEvent.hpp
*/

#ifndef ARCADE_KEYEVENT_HPP
#define ARCADE_KEYEVENT_HPP

#include "IEvent.hpp"
#include "api/window/Keyboard.hpp"

namespace arcade::api::event {
    /**
     * @brief Triggered when key is pressed/released
     */
    class KeyEvent : public IEvent {
        public:
            KeyEvent(window::Keyboard::Key key);
            ~KeyEvent() override = default;

            virtual void setCtrl(bool ctrl) = 0;
            virtual void setAlt(bool alt) = 0;
            virtual void setShift(bool shift) = 0;
            virtual void setSystem(bool system) = 0;

            virtual bool isCtrl() const = 0;
            virtual bool isAlt() const = 0;
            virtual bool isShift() const = 0;
            virtual bool isSystem() const = 0;

            virtual window::Keyboard::Key getKey() const = 0;

        private:
            bool _ctrl;
            bool _alt;
            bool _shift;
            bool _system;
    };
}

#endif //ARCADE_KEYEVENT_HPP
