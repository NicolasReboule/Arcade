/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

class SFML
{
private:
    const std::string _name;
public:
    explicit SFML(const std::string &name);
    virtual ~SFML();
    // virtual void init();
    // virtual void stop();
    inline virtual const std::string &getName() const {return _name;};
};

#endif /* !SFML_HPP_ */
