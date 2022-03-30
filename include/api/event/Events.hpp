/*
** EPITECH PROJECT, 2022
** Events.hpp
** File description:
** Events.hpp
*/

#ifndef ARCADE_EVENTS_HPP
#define ARCADE_EVENTS_HPP

/**
 * @file Events.hpp
 * @brief The only purpose of this class is to provide a way to access the Event
 */

#include "CloseEvent.hpp"
#include "KeyEvent.hpp"
#include "LaunchMenuEvent.hpp"
#include "MouseEvent.hpp"
#include "RestartEvent.hpp"
#include "SwitchEvent.hpp"

using ArcadeEvent = arcade::api::event::IEvent;
using CloseEvent = arcade::api::event::CloseEvent;
using KeyEvent = arcade::api::event::KeyEvent;
using LaunchMenuEvent = arcade::api::event::LaunchMenuEvent;
using MouseEvent = arcade::api::event::MouseEvent;
using RestartEvent = arcade::api::event::RestartEvent;
using SwitchEvent = arcade::api::event::SwitchEvent;

#endif //ARCADE_EVENTS_HPP
