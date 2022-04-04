/*
** EPITECH PROJECT, 2022
** SFMLText.cpp
** File description:
** SFMLText.cpp
*/

#include "sfml/SFMLText.hpp"

arcade::sfml::SFMLText::SFMLText(const Text &text)
    : api::renderer::Text(text.getText(), text.getFontPath(), text.getColor())
{
    if (!this->_font.loadFromFile(text.getFontPath()))
        std::cerr << "Cannot load font: " << text.getFontPath() << std::endl;
    this->_text.setFont(this->_font);
    this->_text.setString(this->_text.getString());
    SFMLText::update(text);
}

void arcade::sfml::SFMLText::update(const arcade::api::renderer::IDrawable &drawable)
{
    try {
        auto text = dynamic_cast<const Text &>(drawable);
        this->_lastUpdate = Time::getNanosecondsTime();
        this->setPosition(text.getPosition());
        this->setRotation(text.getRotation());
        this->setScale(text.getScale());
        this->setOrigin(text.getOrigin());
        this->setColor(text.getColor());
        this->setText(text.getText());
        this->setSize(text.getSize());
        this->setFontPath(text.getFontPath());
        this->setHightlighted(text.isHighlighted());
        this->setHighlightColor(text.getHighlightColor());
    } catch (std::bad_cast &e) {
        throw api::ex::DrawableException("SFMLText::update(): " +  std::string(e.what()));
    }
}

void arcade::sfml::SFMLText::setPosition(const Vector2f &pos)
{
    AbstractDrawable::setPosition(pos);
    this->_text.setPosition({pos.x, pos.y});
}

void arcade::sfml::SFMLText::setPosition(float x, float y)
{
    AbstractDrawable::setPosition(x, y);
    this->_text.setPosition(x, y);
}

void arcade::sfml::SFMLText::setRotation(float rotation)
{
    AbstractDrawable::setRotation(rotation);
    this->_text.setRotation(rotation);
}

void arcade::sfml::SFMLText::setScale(const Vector2f &scale)
{
    AbstractDrawable::setScale(scale);
    this->_text.setScale({scale.x, scale.y});
}

void arcade::sfml::SFMLText::setScale(float factorX, float factorY)
{
    AbstractDrawable::setScale(factorX, factorY);
    this->_text.setScale(factorX, factorY);
}

void arcade::sfml::SFMLText::setOrigin(const Vector2f &origin)
{
    AbstractDrawable::setOrigin(origin);
    this->_text.setOrigin({origin.x, origin.y});
}

void arcade::sfml::SFMLText::setOrigin(float x, float y)
{
    AbstractDrawable::setOrigin(x, y);
    this->_text.setOrigin(x, y);
}

void arcade::sfml::SFMLText::move(const Vector2f &offset)
{
    AbstractDrawable::move(offset);
    this->_text.move({offset.x, offset.y});
}

void arcade::sfml::SFMLText::move(float offsetX, float offsetY)
{
    AbstractDrawable::move(offsetX, offsetY);
    this->_text.move(offsetX, offsetY);
}

void arcade::sfml::SFMLText::rotate(float angle)
{
    AbstractDrawable::rotate(angle);
    this->_text.rotate(angle);
}

void arcade::sfml::SFMLText::scale(const Vector2f &factor)
{
    AbstractDrawable::scale(factor);
    this->_text.scale({factor.x, factor.y});
}

void arcade::sfml::SFMLText::scale(float factorX, float factorY)
{
    AbstractDrawable::scale(factorX, factorY);
    this->_text.scale(factorX, factorY);
}

void arcade::sfml::SFMLText::setSize(const Vector2f &size)
{
    (void) size;
    sf::FloatRect bounds = this->_text.getGlobalBounds();
    AbstractDrawable::setSize({bounds.width, bounds.height});
}

void arcade::sfml::SFMLText::setText(const std::string &text)
{
    Text::setText(text);
    this->_text.setString(text);
}

void arcade::sfml::SFMLText::setFontPath(const std::string &fontPath)
{
    if (this->getFontPath() == fontPath)
        return;
    Text::setFontPath(fontPath);
    this->_font.loadFromFile(fontPath);
    this->_text.setFont(this->_font);
}

void arcade::sfml::SFMLText::setColor(const arcade::api::renderer::Color &color)
{
    Text::setColor(color);
    this->_text.setFillColor(sf::Color(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha()));
}

void arcade::sfml::SFMLText::setHightlighted(bool highlighted)
{
    Text::setHightlighted(highlighted);
    if (highlighted) {
        this->_text.setOutlineColor(sf::Color(this->getHighlightColor().getRed(), this->getHighlightColor().getGreen(), this->getHighlightColor().getBlue(), this->getHighlightColor().getAlpha()));
        this->_text.setOutlineThickness(-2);
    } else {
        this->_text.setOutlineColor(sf::Color::Black);
        this->_text.setOutlineThickness(0);
    }
}

void arcade::sfml::SFMLText::setHighlightColor(const arcade::api::renderer::Color &color)
{
    Text::setHighlightColor(color);
    if (this->isHighlighted())
        this->_text.setOutlineColor(sf::Color(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha()));
}

const sf::Text &arcade::sfml::SFMLText::getSfText() const
{
    return this->_text;
}
