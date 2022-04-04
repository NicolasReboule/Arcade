/*
** EPITECH PROJECT, 2022
** NcText.cpp
** File description:
** NcText.cpp
*/

#include "ncurses/NcText.hpp"

arcade::ncurse::NcText::NcText(api::renderer::Text &text) : api::renderer::Text(text.getText(), text.getFontPath(), text.getColor())
{
    NcText::update(text);
}

void arcade::ncurse::NcText::setPosition(const Vector2f &pos)
{
    AbstractDrawable::setPosition({pos.x / TTY_RATIO, pos.y / TTY_RATIO});
}

void arcade::ncurse::NcText::setPosition(float x, float y)
{
    AbstractDrawable::setPosition(x/TTY_RATIO, y/TTY_RATIO);
}

void arcade::ncurse::NcText::setRotation(float rotation)
{
    AbstractDrawable::setRotation(rotation);
}

void arcade::ncurse::NcText::setScale(const Vector2f &scale)
{
    AbstractDrawable::setScale(scale);
}

void arcade::ncurse::NcText::setScale(float factorX, float factorY)
{
    AbstractDrawable::setScale(factorX, factorY);
}

void arcade::ncurse::NcText::setOrigin(const Vector2f &origin)
{
    AbstractDrawable::setOrigin(origin);
}

void arcade::ncurse::NcText::setOrigin(float x, float y)
{
    AbstractDrawable::setOrigin(x, y);
}

void arcade::ncurse::NcText::move(const Vector2f &offset)
{
    AbstractDrawable::move({offset.x / TTY_RATIO, offset.y / TTY_RATIO});
}

void arcade::ncurse::NcText::move(float offsetX, float offsetY)
{
    AbstractDrawable::move(offsetX / TTY_RATIO, offsetY / TTY_RATIO);
}

void arcade::ncurse::NcText::rotate(float angle)
{
    AbstractDrawable::rotate(angle);
}

void arcade::ncurse::NcText::scale(const Vector2f &factor)
{
    AbstractDrawable::scale(factor);
}

void arcade::ncurse::NcText::scale(float factorX, float factorY)
{
    AbstractDrawable::scale(factorX, factorY);
}

void arcade::ncurse::NcText::setSize(const Vector2f &size)
{
    AbstractDrawable::setSize(size);
}

void
arcade::ncurse::NcText::update(const arcade::api::renderer::IDrawable &drawable)
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
        throw api::ex::DrawableException("NcText::update(): " +  std::string(e.what()));
    }
}

void arcade::ncurse::NcText::setText(const std::string &text)
{
    Text::setText(text);
}

void arcade::ncurse::NcText::setFontPath(const std::string &fontPath)
{
    Text::setFontPath(fontPath);
}

void arcade::ncurse::NcText::setColor(const arcade::api::renderer::Color &color)
{
    Text::setColor(color);
}

void arcade::ncurse::NcText::setHightlighted(bool highlighted)
{
    Text::setHightlighted(highlighted);
}

void arcade::ncurse::NcText::setHighlightColor(
    const arcade::api::renderer::Color &color)
{
    Text::setHighlightColor(color);
}

void arcade::ncurse::NcText::draw(WINDOW *window)
{
    mvwprintw(window, this->getPosition().y, this->getPosition().x, "%s", this->getText().c_str());
}
