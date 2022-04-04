/*
** EPITECH PROJECT, 2022
** SFMLRectangle.cpp
** File description:
** SFMLRectangle.cpp
*/

#include "sfml/SFMLRectangle.hpp"

arcade::sfml::SFMLRectangle::SFMLRectangle(const Rectangle &rectangle)
    : Rectangle(rectangle.getFillColor(), rectangle.getBorderColor(), rectangle.getSize(), rectangle.isFilled())
{
    SFMLRectangle::update(rectangle);
}

void arcade::sfml::SFMLRectangle::update(const arcade::api::renderer::IDrawable &drawable)
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
        throw api::ex::DrawableException("SFMLRectangle::update(): " +  std::string(e.what()));
    }
}

void arcade::sfml::SFMLRectangle::setFillColor(const arcade::api::renderer::Color &color)
{
    Rectangle::setFillColor(color);
    if (!this->isFilled())
        this->_rectangle.setFillColor(sf::Color::Transparent);
    else
        this->_rectangle.setFillColor(sf::Color(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha()));
}

void arcade::sfml::SFMLRectangle::setBorderColor(const arcade::api::renderer::Color &color)
{
    Rectangle::setBorderColor(color);
    this->_rectangle.setOutlineColor(sf::Color(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha()));
    this->_rectangle.setOutlineThickness(-1);
}

void arcade::sfml::SFMLRectangle::setPosition(const Vector2f &pos)
{
    AbstractDrawable::setPosition(pos);
    this->_rectangle.setPosition({pos.x, pos.y});
}

void arcade::sfml::SFMLRectangle::setPosition(float x, float y)
{
    AbstractDrawable::setPosition(x, y);
    this->_rectangle.setPosition(x, y);
}

void arcade::sfml::SFMLRectangle::setRotation(float rotation)
{
    AbstractDrawable::setRotation(rotation);
    this->_rectangle.setRotation(rotation);
}

void arcade::sfml::SFMLRectangle::setScale(const Vector2f &scale)
{
    AbstractDrawable::setScale(scale);
    this->_rectangle.setScale({scale.x, scale.y});
}

void arcade::sfml::SFMLRectangle::setScale(float factorX, float factorY)
{
    AbstractDrawable::setScale(factorX, factorY);
    this->_rectangle.setScale(factorX, factorY);
}

void arcade::sfml::SFMLRectangle::setOrigin(const Vector2f &origin)
{
    AbstractDrawable::setOrigin(origin);
    this->_rectangle.setOrigin({origin.x, origin.y});
}

void arcade::sfml::SFMLRectangle::setOrigin(float x, float y)
{
    AbstractDrawable::setOrigin(x, y);
    this->_rectangle.setOrigin(x, y);
}

void arcade::sfml::SFMLRectangle::move(const Vector2f &offset)
{
    AbstractDrawable::move(offset);
    this->_rectangle.move({offset.x, offset.y});
}

void arcade::sfml::SFMLRectangle::move(float offsetX, float offsetY)
{
    AbstractDrawable::move(offsetX, offsetY);
    this->_rectangle.move(offsetX, offsetY);
}

void arcade::sfml::SFMLRectangle::rotate(float angle)
{
    AbstractDrawable::rotate(angle);
    this->_rectangle.rotate(angle);
}

void arcade::sfml::SFMLRectangle::scale(const Vector2f &factor)
{
    AbstractDrawable::scale(factor);
    this->_rectangle.scale({factor.x, factor.y});
}

void arcade::sfml::SFMLRectangle::scale(float factorX, float factorY)
{
    AbstractDrawable::scale(factorX, factorY);
    this->_rectangle.scale(factorX, factorY);
}

void arcade::sfml::SFMLRectangle::setSize(const Vector2f &size)
{
    AbstractDrawable::setSize(size);
    this->_rectangle.setSize({size.x, size.y});
}

const sf::RectangleShape &arcade::sfml::SFMLRectangle::getShape()
{
    return this->_rectangle;
}
