/*
** EPITECH PROJECT, 2022
** NcRectangle.cpp
** File description:
** NcRectangle.cpp
*/

#include "ncurses/NcRectangle.hpp"

arcade::ncurse::NcRectangle::NcRectangle(api::renderer::Rectangle &rect) : api::renderer::Rectangle(rect.getFillColor(), rect.getBorderColor(), rect.getSize(), rect.isFilled())
{
    NcRectangle::update(rect);
}

void arcade::ncurse::NcRectangle::setPosition(const Vector2f &pos)
{
    AbstractDrawable::setPosition({pos.x / TTY_RATIO, pos.y / TTY_RATIO});
}

void arcade::ncurse::NcRectangle::setPosition(float x, float y)
{
    AbstractDrawable::setPosition(x/TTY_RATIO, y/TTY_RATIO);
}

void arcade::ncurse::NcRectangle::setRotation(float rotation)
{
    AbstractDrawable::setRotation(rotation);
}

void arcade::ncurse::NcRectangle::setScale(const Vector2f &scale)
{
    AbstractDrawable::setScale(scale);
}

void arcade::ncurse::NcRectangle::setScale(float factorX, float factorY)
{
    AbstractDrawable::setScale(factorX, factorY);
}

void arcade::ncurse::NcRectangle::setOrigin(const Vector2f &origin)
{
    AbstractDrawable::setOrigin(origin);
}

void arcade::ncurse::NcRectangle::setOrigin(float x, float y)
{
    AbstractDrawable::setOrigin(x, y);
}

void arcade::ncurse::NcRectangle::move(const Vector2f &offset)
{
    AbstractDrawable::move({offset.x / TTY_RATIO, offset.y / TTY_RATIO});
}

void arcade::ncurse::NcRectangle::move(float offsetX, float offsetY)
{
    AbstractDrawable::move(offsetX / TTY_RATIO, offsetY / TTY_RATIO);
}

void arcade::ncurse::NcRectangle::rotate(float angle)
{
    AbstractDrawable::rotate(angle);
}

void arcade::ncurse::NcRectangle::scale(const Vector2f &factor)
{
    AbstractDrawable::scale(factor);
}

void arcade::ncurse::NcRectangle::scale(float factorX, float factorY)
{
    AbstractDrawable::scale(factorX, factorY);
}

void arcade::ncurse::NcRectangle::setSize(const Vector2f &size)
{
    AbstractDrawable::setSize(size);
}

void arcade::ncurse::NcRectangle::update(
    const arcade::api::renderer::IDrawable &drawable)
{
    try {
        auto rectangle = dynamic_cast<const Rectangle &>(drawable);
        this->_lastUpdate = Time::getNanosecondsTime();
        this->setSize(rectangle.getSize());
        this->setFillColor(rectangle.getFillColor());
        this->setBorderColor(rectangle.getBorderColor());
        this->setPosition(rectangle.getPosition());
        this->setRotation(rectangle.getRotation());
        this->setScale(rectangle.getScale());
        this->setOrigin(rectangle.getOrigin());
    } catch (std::bad_cast &e) {
        throw api::ex::DrawableException("NcRectangle::update(): " +  std::string(e.what()));
    }
}

void arcade::ncurse::NcRectangle::setFillColor(
    const arcade::api::renderer::Color &color)
{
    Rectangle::setFillColor(color);
}

void arcade::ncurse::NcRectangle::setBorderColor(
    const arcade::api::renderer::Color &color)
{
    Rectangle::setBorderColor(color);
}

void arcade::ncurse::NcRectangle::draw(WINDOW *window)
{
    for (api::NColors color : api::COLORS) {
        if (this->getBorderColor() == color.color)
            wattron(window, COLOR_PAIR(color.idx));
    }
    int x = (int)this->getPosition().x;
    int y = (int)this->getPosition().y;
    int h = (int)this->getSize().y;
    int w = (int)this->getSize().x;

    mvwhline(window, y, x, 0, w);
    mvwhline(window, y + h, x, 0, w);
    mvwvline(window, y, x, 0, h);
    mvwvline(window, y, x + w, 0, h);
    mvwaddch(window, y, x, ACS_ULCORNER);
    mvwaddch(window, y + h, x, ACS_LLCORNER);
    mvwaddch(window, y, x + w, ACS_URCORNER);
    mvwaddch(window, y + x, x + w, ACS_LRCORNER);
}
