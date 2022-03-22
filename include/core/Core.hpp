/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <list>
#include "DlManager.hpp"
namespace arcade
{
    class Core
    {
        public:
            explicit Core(std::list<std::string> games, std::list<std::string> displays) : _manager(games, displays) {};
            ~Core() = default;
            void run();
            void setGame(const std::string &);
            void setDisplay(const std::string &);
            std::string getGame(void);
        private:
            DlManager _manager;
    };
}


#endif /* !CORE_HPP_ */
