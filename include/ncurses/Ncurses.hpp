/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
    #define NCURSES_HPP_
    #include "IDisplayModule.hpp"
    #include "IGameModule.hpp"
    #include "ncurses.h"

namespace arcade::api
{
    class Curses : public IDisplayModule {
        public:
            explicit Curses(const std::string &name);

            void init() override;
            void destroy() override;
            void run() override;
            void display() override;
            void update() override;
            bool isOpen() const override;
            void clear() override;
            inline WINDOW *getWindow() { return this->_window; };
            const std::string &getName() const override;
            IDisplayModule *getInstance() override;
            bool pollEvent(event::IEvent &event) override;
            std::shared_ptr<arcade::api::Curses> entryPoint(void);

        protected:
            std::string _name;
            WINDOW *_window;
            bool _isOpen;
            std::shared_ptr<IGameModule> _game;
    };
}
#endif /* !NCURSES_HPP_ */
