/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "DlManager.hpp"

namespace arcade
{
    class Core
    {
        public:
            explicit Core();
            ~Core() = default;
            void init();
            void run();
        private:
            DlManager _manager;
            bool isRunning;
    };
}


#endif /* !CORE_HPP_ */
