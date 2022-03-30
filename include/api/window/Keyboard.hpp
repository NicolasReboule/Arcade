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

inline std::ostream &operator<<(std::ostream &os, const KeyCode code)
{
    if (code == KeyCode::Unknown)
        os << "Unknown";
    else if (code >= KeyCode::A && code <= KeyCode::Z)
        os << static_cast<char>('A' + code);
    else if (code >= KeyCode::Num0 && code <= KeyCode::Num9)
        os << static_cast<char>('0' + (code - KeyCode::Num0));
    else if (code >= KeyCode::Numpad0 && code <= KeyCode::Numpad9)
        os << "NumPad" << static_cast<char>('0' + (code - KeyCode::Numpad0));
    else if (code >= KeyCode::F1 && code <= KeyCode::F9)
        os << "F" << static_cast<char>('0' + (code - KeyCode::F1 + 1));
    else if (code >= KeyCode::F10 && code <= KeyCode::F15)
        os << "F1" << static_cast<char>('0' + (code - KeyCode::F10));
    switch (code) {
        case KeyCode::Escape: os << "Escape"; break;
        case KeyCode::LControl: os << "LControl"; break;
        case KeyCode::LShift: os << "LShift"; break;
        case KeyCode::LAlt: os << "LAlt"; break;
        case KeyCode::LSystem: os << "LSystem"; break;
        case KeyCode::RControl: os << "RControl"; break;
        case KeyCode::RShift: os << "RShift"; break;
        case KeyCode::RAlt: os << "RAlt"; break;
        case KeyCode::RSystem: os << "RSystem"; break;
        case KeyCode::Menu: os << "Menu"; break;
        case KeyCode::LBracket: os << "]"; break;
        case KeyCode::RBracket: os << "["; break;
        case KeyCode::Semicolon: os << ";"; break;
        case KeyCode::Comma: os << ","; break;
        case KeyCode::Period: os << "."; break;
        case KeyCode::Quote: os << "'"; break;
        case KeyCode::Slash: os << "/"; break;
        case KeyCode::Backslash: os << "\\"; break;
        case KeyCode::Tilde: os << "~"; break;
        case KeyCode::Equal: os << "="; break;
        case KeyCode::Hyphen: os << "-"; break;
        case KeyCode::Space: os << "Space"; break;
        case KeyCode::Enter: os << "Enter"; break;
        case KeyCode::Backspace: os << "Backspace"; break;
        case KeyCode::Tab: os << "Tab"; break;
        case KeyCode::PageUp: os << "PageUp"; break;
        case KeyCode::PageDown: os << "PageDown"; break;
        case KeyCode::End: os << "End"; break;
        case KeyCode::Home: os << "Home"; break;
        case KeyCode::Insert: os << "Insert"; break;
        case KeyCode::Delete: os << "Delete"; break;
        case KeyCode::Add: os << "+"; break;
        case KeyCode::Subtract: os << "-"; break;
        case KeyCode::Multiply: os << "*"; break;
        case KeyCode::Divide: os << "/"; break;
        case KeyCode::Left: os << "Left"; break;
        case KeyCode::Right: os << "Right"; break;
        case KeyCode::Up: os << "Up"; break;
        case KeyCode::Down: os << "Down"; break;
        case KeyCode::Pause : os << "Pause"; break;
        default: break;
    }
    return os;
}

inline std::ostream &operator<<(std::ostream &os, const KeyAction action)
{
    if (action == KeyAction::PRESSED)
        os << "Pressed";
    else if (action == KeyAction::RELEASED)
        os << "Released";
    return os;
}

#endif //ARCADE_KEYBOARD_HPP
