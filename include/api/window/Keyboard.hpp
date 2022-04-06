/*
** EPITECH PROJECT, 2022
** Keyboard.hpp
** File description:
** Keyboard.hpp
*/

#ifndef ARCADE_KEYBOARD_HPP
#define ARCADE_KEYBOARD_HPP

#include <iostream>

namespace arcade::api::window {
    /**
     * @brief Class containing the keyboard keys & actions
     */
    class Keyboard {
    public:
        /**
         * @brief KeyAction
         */
        enum KeyAction {
            PRESSED, /**< Key is pressed */
            RELEASED /**< Key is released */
        };

        /**
         * @brief KeyCode
         */
        enum Key {
            Unknown = -1, /**< Unhandled key */
            A = 0,        /**< The A key */
            B,            /**< The B key */
            C,            /**< The C key */
            D,            /**< The D key */
            E,            /**< The E key */
            F,            /**< The F key */
            G,            /**< The G key */
            H,            /**< The H key */
            I,            /**< The I key */
            J,            /**< The J key */
            K,            /**< The K key */
            L,            /**< The L key */
            M,            /**< The M key */
            N,            /**< The N key */
            O,            /**< The O key */
            P,            /**< The P key */
            Q,            /**< The Q key */
            R,            /**< The R key */
            S,            /**< The S key */
            T,            /**< The T key */
            U,            /**< The U key */
            V,            /**< The V key */
            W,            /**< The W key */
            X,            /**< The X key */
            Y,            /**< The Y key */
            Z,            /**< The Z key */
            Num0,         /**< The 0 key */
            Num1,         /**< The 1 key */
            Num2,         /**< The 2 key */
            Num3,         /**< The 3 key */
            Num4,         /**< The 4 key */
            Num5,         /**< The 5 key */
            Num6,         /**< The 6 key */
            Num7,         /**< The 7 key */
            Num8,         /**< The 8 key */
            Num9,         /**< The 9 key */
            Escape,       /**< The Escape key */
            LControl,     /**< The left Control key */
            LShift,       /**< The left Shift key */
            LAlt,         /**< The left Alt key */
            LSystem,      /**< The left OS specific key: window (Windows and Linux), apple (MacOS X), ... */
            RControl,     /**< The right Control key */
            RShift,       /**< The right Shift key */
            RAlt,         /**< The right Alt key */
            RSystem,      /**< The right OS specific key: window (Windows and Linux), apple (MacOS X), ... */
            Menu,         /**< The Menu key */
            LBracket,     /**< The [ key */
            RBracket,     /**< The ] key */
            Semicolon,    /**< The ; key */
            Comma,        /**< The , key */
            Period,       /**< The . key */
            Quote,        /**< The ' key */
            Slash,        /**< The / key */
            Backslash,    /**< The \ key */
            Tilde,        /**< The ~ key */
            Equal,        /**< The = key */
            Hyphen,       /**< The - key (hyphen) */
            Space,        /**< The Space key */
            Enter,        /**< The Enter/Return keys */
            Backspace,    /**< The Backspace key */
            Tab,          /**< The Tabulation key */
            PageUp,       /**< The Page up key */
            PageDown,     /**< The Page down key */
            End,          /**< The End key */
            Home,         /**< The Home key */
            Insert,       /**< The Insert key */
            Delete,       /**< The Delete key */
            Add,          /**< The + key */
            Subtract,     /**< The - key (minus, usually from numpad) */
            Multiply,     /**< The * key */
            Divide,       /**< The / key */
            Left,         /**< Left arrow */
            Right,        /**< Right arrow */
            Up,           /**< Up arrow */
            Down,         /**< Down arrow */
            Numpad0,      /**< The numpad 0 key */
            Numpad1,      /**< The numpad 1 key */
            Numpad2,      /**< The numpad 2 key */
            Numpad3,      /**< The numpad 3 key */
            Numpad4,      /**< The numpad 4 key */
            Numpad5,      /**< The numpad 5 key */
            Numpad6,      /**< The numpad 6 key */
            Numpad7,      /**< The numpad 7 key */
            Numpad8,      /**< The numpad 8 key */
            Numpad9,      /**< The numpad 9 key */
            F1,           /**< The F1 key */
            F2,           /**< The F2 key */
            F3,           /**< The F3 key */
            F4,           /**< The F4 key */
            F5,           /**< The F5 key */
            F6,           /**< The F6 key */
            F7,           /**< The F7 key */
            F8,           /**< The F8 key */
            F9,           /**< The F9 key */
            F10,          /**< The F10 key */
            F11,          /**< The F11 key */
            F12,          /**< The F12 key */
            F13,          /**< The F13 key */
            F14,          /**< The F14 key */
            F15,          /**< The F15 key */
            Pause,        /**< The Pause key */

            KeyCount,     /**< Keep last -- the total number of keyboard keys */
        };
    };
}

using KeyCode = arcade::api::window::Keyboard::Key; /**< typedef because it's too long */
using KeyAction = arcade::api::window::Keyboard::KeyAction; /**< typedef because it's too long */

/**
 * @brief Get a string from the KeyCode
 * @param code the key code
 * @return the key code in string
 */
inline std::string operator*(const KeyCode code)
{
    if (code == KeyCode::Unknown)
        return "Unknown";
    else if (code >= KeyCode::A && code <= KeyCode::Z)
        return std::string("") + static_cast<char>('A' + code);
    else if (code >= KeyCode::Num0 && code <= KeyCode::Num9)
        return std::string("") + static_cast<char>('0' + (code - KeyCode::Num0));
    else if (code >= KeyCode::Numpad0 && code <= KeyCode::Numpad9)
        return std::string("NumPad") + static_cast<char>('0' + (code - KeyCode::Numpad0));
    else if (code >= KeyCode::F1 && code <= KeyCode::F9)
        return std::string("F") + static_cast<char>('0' + (code - KeyCode::F1 + 1));
    else if (code >= KeyCode::F10 && code <= KeyCode::F15)
        return std::string("F1") + static_cast<char>('0' + (code - KeyCode::F10));
    switch (code) {
        case KeyCode::Escape: return "Escape";
        case KeyCode::LControl: return "LControl";
        case KeyCode::LShift: return "LShift";
        case KeyCode::LAlt: return "LAlt";
        case KeyCode::LSystem: return "LSystem";
        case KeyCode::RControl: return "RControl";
        case KeyCode::RShift: return "RShift";
        case KeyCode::RAlt: return "RAlt";
        case KeyCode::RSystem: return "RSystem";
        case KeyCode::Menu: return "Menu";
        case KeyCode::LBracket: return "]";
        case KeyCode::RBracket: return "[";
        case KeyCode::Semicolon: return ";";
        case KeyCode::Comma: return ",";
        case KeyCode::Period: return ".";
        case KeyCode::Quote: return "'";
        case KeyCode::Slash: return "/";
        case KeyCode::Backslash: return "\\";
        case KeyCode::Tilde: return "~";
        case KeyCode::Equal: return "=";
        case KeyCode::Hyphen: return "-";
        case KeyCode::Space: return "Space";
        case KeyCode::Enter: return "Enter";
        case KeyCode::Backspace: return "Backspace";
        case KeyCode::Tab: return "Tab";
        case KeyCode::PageUp: return "PageUp";
        case KeyCode::PageDown: return "PageDown";
        case KeyCode::End: return "End";
        case KeyCode::Home: return "Home";
        case KeyCode::Insert: return "Insert";
        case KeyCode::Delete: return "Delete";
        case KeyCode::Add: return "+";
        case KeyCode::Subtract: return "-";
        case KeyCode::Multiply: return "*";
        case KeyCode::Divide: return "/";
        case KeyCode::Left: return "Left";
        case KeyCode::Right: return "Right";
        case KeyCode::Up: return "Up";
        case KeyCode::Down: return "Down";
        case KeyCode::Pause : return "Pause";
        default: break;
    }
    return "";
}

/**
 * @brief Show the KeyCode in ostream
 * @param os the ostream
 * @param code the key code
 * @return the ostream with the key code
 */
inline std::ostream &operator<<(std::ostream &os, const KeyCode code)
{
    os << *code;
    return os;
}

/**
 * @brief Show the KeyAction in ostream
 * @param os the ostream
 * @param action the key action
 * @return the osteam with the key action
 */
inline std::ostream &operator<<(std::ostream &os, const KeyAction action)
{
    if (action == KeyAction::PRESSED)
        os << "Pressed";
    else if (action == KeyAction::RELEASED)
        os << "Released";
    return os;
}

#endif //ARCADE_KEYBOARD_HPP
