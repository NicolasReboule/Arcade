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

        void checkHighScore();

        void saveHighScore(const std::string &gameName, std::size_t score) override;

        void loadHighScore(const std::string &dirPath) override;

        std::pair<std::string, std::size_t> getHighScore(const std::string &gameName);

        bool hasHighScore(const std::string &gameName);
    private:
        DlManager _manager;
        menu::MainMenu *_menu;
    };
}

#endif /* !CORE_HPP_ */
