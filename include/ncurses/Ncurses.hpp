/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
    #define NCURSES_HPP_
    #include "ADisplayModule.hpp"
    #include "ncurses.h"

namespace arcade::api
{
    class Curses : public ADisplayModule {
        public:
            explicit Curses(const std::string &name, IGameModule &game);
            explicit Curses(const std::string &name);

            void init() override;
            void destroy() override;
            void run() override;
            void display() override;
            void update() override;
            bool isOpen() const override;
            void clear() override;
            inline WINDOW *getWindow() { return this->_window; };
            std::shared_ptr<Curses> entryPoint(void);

        protected:
            std::string _name;
            WINDOW *_window;
            bool _isOpen;
    };
}
#endif /* !NCURSES_HPP_ */
