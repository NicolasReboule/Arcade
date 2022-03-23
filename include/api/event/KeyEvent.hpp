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
        /**
         * Constructor of KeyEvent
         * @param key the key triggered
         * @param action the action of the key @see KeyAction
         */
        explicit KeyEvent(window::Keyboard::Key key, window::Keyboard::KeyAction action)
        {
            this->_key = key;
            this->_action = action;
        }

        /**
         * Set if the ctrl key is pressed with another key
         * @param ctrl if ctrl key is pressed
         */
        inline void setCtrl(bool ctrl)
        {
            this->_ctrl = ctrl;
        }

        /**
         * Set if the alt key is pressed with another key
         * @param alt if alt key is pressed
         */
        inline void setAlt(bool alt)
        {
            this->_alt = alt;
        }

        /**
         * Set if the shift key is pressed with another key
         * @param shift if shift key is pressed
         */
        inline void setShift(bool shift)
        {
            this->_shift = shift;
        }

        /**
         * Set if the system key is pressed with another key
         * @param system if system key is pressed
         */
        inline void setSystem(bool system)
        {
            this->_system = system;
        }

        /**
         * Check if the ctrl key is pressed
         * @return if ctrl key is pressed
         */
        inline bool isCtrl() const
        {
            return this->_ctrl;
        }

        /**
         * Check if the alt key is pressed
         * @return if alt key is pressed
         */
        inline bool isAlt() const
        {
            return this->_alt;
        }

        /**
         * Check if the shift key is pressed
         * @return if shift key is pressed
         */
        inline bool isShift() const
        {
            return this->_shift;
        }

        /**
         * Check if the system key is pressed
         * @return if system is pressed
         */
        inline bool isSystem() const
        {
            return this->_system;
        }

        /**
         * Get the key triggered
         * @return the key
         */
        inline window::Keyboard::Key getKey() const
        {
            return this->_key;
        }

        /**
         * Get the action the key
         * @return the action of the key
         */
        inline window::Keyboard::KeyAction getAction() const
        {
            return this->_action;
        }

        /**
         * Get if the key is pressed
         * @return if the key is pressed
         */
        inline bool isPressed() const
        {
            return this->_action == window::Keyboard::KeyAction::PRESSED;
        }

        /**
         * Get if the key is released
         * @return if the key is released
         */
        inline bool isReleased() const
        {
            return this->_action == window::Keyboard::KeyAction::RELEASED;
        }

    private:
        window::Keyboard::Key _key; /**< The key triggered */
        window::Keyboard::KeyAction _action /**< The action of the key */;
        bool _ctrl; /**< If ctrl key is pressed */
        bool _alt; /**< If alt key is pressed */
        bool _shift; /**< If shift key is pressed */
        bool _system; /**< If system key is pressed */
    };
}

#endif //ARCADE_KEYEVENT_HPP
