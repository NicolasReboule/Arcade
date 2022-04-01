/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "api/AbstractGameModule.hpp"
namespace arcade::api {
    class Nibbler : public AbstractGameModule
    {
        public:
            explicit Nibbler();
            ~Nibbler();
            inline void init() override {};
            inline void destroy() override {};

        bool isRunning() override;

        inline const std::string &getName() const override {return _name;};
            static Nibbler *getInstance();
            inline void onEvent(event::IEvent &event) override {};
            inline void render(IDisplayModule &display) override {};
            inline LibraryType getType() const { return GAME; }

        void update(std::size_t tick) override;

        void restart() override;

    private:
        static std::unique_ptr<Nibbler> _instance;
        std::string _name;
    };
}

#endif /* !NIBBLER_HPP_ */
