/*
** EPITECH PROJECT, 2022
** SFMLSprite.cpp
** File description:
** SFMLSprite.cpp
*/

#include "sfml/SFMLSprite.hpp"

arcade::sfml::SFMLSprite::SFMLSprite(const Sprite &sprite)
    : Sprite(sprite.getTexturePath(), sprite.getSymbol())
{
    this->_texture.loadFromFile(this->_texturePath);
    this->_sprite.setTexture(_texture);
    SFMLSprite::update(sprite);
}

void arcade::sfml::SFMLSprite::update(const arcade::api::renderer::IDrawable &drawable)
{
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
        throw api::ex::DrawableException("SFMLSprite::update(): " +  std::string(e.what()));
    }
}

void arcade::sfml::SFMLSprite::setPosition(const Vector2f &pos)
{
    AbstractDrawable::setPosition(pos);
    this->_sprite.setPosition({pos.x, pos.y});
}

void arcade::sfml::SFMLSprite::setPosition(float x, float y)
{
    AbstractDrawable::setPosition(x, y);
    this->_sprite.setPosition(x, y);
}

void arcade::sfml::SFMLSprite::setRotation(float rotation)
{
    AbstractDrawable::setRotation(rotation);
    this->_sprite.setRotation(rotation);
}

void arcade::sfml::SFMLSprite::setScale(const Vector2f &scale)
{
    AbstractDrawable::setScale(scale);
    this->_sprite.setScale({scale.x, scale.y});
}

void arcade::sfml::SFMLSprite::setScale(float factorX, float factorY)
{
    AbstractDrawable::setScale(factorX, factorY);
    this->_sprite.setScale(factorX, factorY);
}

void arcade::sfml::SFMLSprite::setOrigin(const Vector2f &origin)
{
    AbstractDrawable::setOrigin(origin);
    this->_sprite.setOrigin({origin.x, origin.y});
}

void arcade::sfml::SFMLSprite::setOrigin(float x, float y)
{
    AbstractDrawable::setOrigin(x, y);
    this->_sprite.setOrigin(x, y);
}

void arcade::sfml::SFMLSprite::move(const Vector2f &offset)
{
    AbstractDrawable::move(offset);
    this->_sprite.move({offset.x, offset.y});
}

void arcade::sfml::SFMLSprite::move(float offsetX, float offsetY)
{
    AbstractDrawable::move(offsetX, offsetY);
    this->_sprite.move(offsetX, offsetY);
}

void arcade::sfml::SFMLSprite::rotate(float angle)
{
    AbstractDrawable::rotate(angle);
    this->_sprite.rotate(angle);
}

void arcade::sfml::SFMLSprite::scale(const Vector2f &factor)
{
    AbstractDrawable::scale(factor);
    this->_sprite.scale({factor.x, factor.y});
}

void arcade::sfml::SFMLSprite::scale(float factorX, float factorY)
{
    AbstractDrawable::scale(factorX, factorY);
    this->_sprite.scale(factorX, factorY);
}

void arcade::sfml::SFMLSprite::setSize(const Vector2f &size)
{
    (void) size;
    sf::FloatRect bounds = this->_sprite.getGlobalBounds();
    AbstractDrawable::setSize({bounds.width, bounds.height});
}

void arcade::sfml::SFMLSprite::setColor(const arcade::api::renderer::Color &color)
{
    Sprite::setColor(color);
    this->_sprite.setColor(sf::Color(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha()));
}

void arcade::sfml::SFMLSprite::setTexturePath(const std::string &texturePath)
{
    if (this->_texturePath == texturePath)
        return;
    Sprite::setTexturePath(texturePath);
    this->_texture.loadFromFile(this->_texturePath);
    this->_sprite.setTexture(_texture);
}

const sf::Sprite &arcade::sfml::SFMLSprite::getSprite() const
{
    return this->_sprite;
}
