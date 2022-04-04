/*
** EPITECH PROJECT, 2022
** NcSprite.cpp
** File description:
** NcSprite.cpp
*/

#include "ncurses/NcSprite.hpp"

arcade::ncurse::NcSprite::NcSprite(api::renderer::Sprite &sprite) : api::renderer::Sprite(sprite.getTexturePath(), sprite.getSymbol())
{
    NcSprite::update(sprite);
}

void arcade::ncurse::NcSprite::setPosition(const Vector2f &pos)
{
    AbstractDrawable::setPosition({pos.x/TTY_RATIO, pos.y / TTY_RATIO});
}

void arcade::ncurse::NcSprite::setPosition(float x, float y)
{
    AbstractDrawable::setPosition(x / TTY_RATIO, y / TTY_RATIO);
}

void arcade::ncurse::NcSprite::setRotation(float rotation)
{
    AbstractDrawable::setRotation(rotation);
}

void arcade::ncurse::NcSprite::setScale(const Vector2f &scale)
{
    AbstractDrawable::setScale(scale);
}

void arcade::ncurse::NcSprite::setScale(float factorX, float factorY)
{
    AbstractDrawable::setScale(factorX, factorY);
}

void arcade::ncurse::NcSprite::setOrigin(const Vector2f &origin)
{
    AbstractDrawable::setOrigin(origin);
}

void arcade::ncurse::NcSprite::setOrigin(float x, float y)
{
    AbstractDrawable::setOrigin(x, y);
}

void arcade::ncurse::NcSprite::move(const Vector2f &offset)
{
    AbstractDrawable::move({offset.x / TTY_RATIO, offset.y / TTY_RATIO});
}

void arcade::ncurse::NcSprite::move(float offsetX, float offsetY)
{
    AbstractDrawable::move(offsetX / TTY_RATIO, offsetY / TTY_RATIO);
}

void arcade::ncurse::NcSprite::rotate(float angle)
{
    AbstractDrawable::rotate(angle);
}

void arcade::ncurse::NcSprite::scale(const Vector2f &factor)
{
    AbstractDrawable::scale(factor);
}

void arcade::ncurse::NcSprite::scale(float factorX, float factorY)
{
    AbstractDrawable::scale(factorX, factorY);
}

void arcade::ncurse::NcSprite::setSize(const Vector2f &size)
{
    AbstractDrawable::setSize(size);
}

void arcade::ncurse::NcSprite::update(
    const arcade::api::renderer::IDrawable &drawable)
{
    Sprite::update(drawable);
    try {
        auto sprite = dynamic_cast<const Sprite &>(drawable);
        this->_lastUpdate = Time::getNanosecondsTime();
        this->setPosition(sprite.getPosition());
        this->setRotation(sprite.getRotation());
        this->setScale(sprite.getScale());
        this->setOrigin(sprite.getOrigin());
        this->setColor(sprite.getColor());
        this->setTexturePath(sprite.getTexturePath());
    } catch (std::bad_cast &e) {
        throw api::ex::DrawableException("NcSprite::update(): " +  std::string(e.what()));
    }
}

void
arcade::ncurse::NcSprite::setColor(const arcade::api::renderer::Color &color)
{
    Sprite::setColor(color);
}

void arcade::ncurse::NcSprite::setTexturePath(const std::string &texturePath)
{
    Sprite::setTexturePath(texturePath);
}

void arcade::ncurse::NcSprite::draw(WINDOW *window)
{
    mvwprintw(window, this->getPosition().y, this->getPosition().x, "%c", this->getSymbol());
}
