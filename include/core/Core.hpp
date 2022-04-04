/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "DlManager.hpp"
#include "api/AbstractCore.hpp"

namespace arcade {
    namespace menu {
        class MainMenu;
    }
    class Core : public api::AbstractCore {
    public:
        Core();
        ~Core() = default;

        void init(const std::string &);
        void handleEvent(const std::unique_ptr<ArcadeEvent> &event) override;
        void run();

        void stop() override;

        void update() override;

        api::library::IDLManager &getDLManager() override;

        void setUsername(const std::string &username) override;

        const std::string &getUsername() const override;

    private:
        DlManager _manager;
        menu::MainMenu *_menu;
    };
}

#endif /* !CORE_HPP_ */
