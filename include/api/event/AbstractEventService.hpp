/*
** EPITECH PROJECT, 2022
** AbstractEventService.hpp
** File description:
** AbstractEventService.hpp
*/

#ifndef ARCADE_ABSTRACTEVENTSERVICE_HPP
#define ARCADE_ABSTRACTEVENTSERVICE_HPP

#include "api/event/IEventHandler.hpp"
#include <list>

namespace arcade::api::event {
    class AbstractEventService {
    public:
        AbstractEventService() = default;
        virtual ~AbstractEventService() = default;

        /**
         * @brief Add an event handler to the service
         * @param handler the handler to add
         */
        virtual void addHandler(IEventHandler &handler) = 0;

        /**
         * @brief Remove an event handler from the service
         * @param handler the handler to remove
         */
        virtual void removeHandler(IEventHandler &handler) = 0;

        /**
         * @brief Get the list of event handler
         * @return the list of event handler
         */
        virtual std::list<IEventHandler *> &getHandlers() = 0;

    private:
        std::list<IEventHandler *> _handlers;
    };
}

#endif //ARCADE_ABSTRACTEVENTSERVICE_HPP
