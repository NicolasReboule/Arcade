/*
** EPITECH PROJECT, 2022
** SDLRectangle.cpp
** File description:
** SDLRectangle.cpp
*/

#include "sdl2/SDLRectangle.hpp"

arcade::sdl::SDLRectangle::SDLRectangle(const Rectangle &rect) : api::renderer::Rectangle(rect.getFillColor(), rect.getBorderColor(), rect.getSize(), rect.isFilled())
{
    SDLRectangle::update(rect);
}

void arcade::sdl::SDLRectangle::setPosition(const Vector2f &pos)
{
    AbstractDrawable::setPosition(pos);
}


void arcade::sdl::SDLRectangle::setPosition(float x, float y)
{
    AbstractDrawable::setPosition(x, y);
}

void arcade::sdl::SDLRectangle::setRotation(float rotation)
{
    AbstractDrawable::setRotation(rotation);
}

void arcade::sdl::SDLRectangle::setScale(const Vector2f &scale)
{
    AbstractDrawable::setScale(scale);
}

void arcade::sdl::SDLRectangle::setScale(float factorX, float factorY)
{
    AbstractDrawable::setScale(factorX, factorY);
}

void arcade::sdl::SDLRectangle::setOrigin(const Vector2f &origin)
{
    AbstractDrawable::setOrigin(origin);
}

void arcade::sdl::SDLRectangle::setOrigin(float x, float y)
{
    AbstractDrawable::setOrigin(x, y);
}

void arcade::sdl::SDLRectangle::move(const Vector2f &offset)
{
    AbstractDrawable::move(offset);
}

void arcade::sdl::SDLRectangle::move(float offsetX, float offsetY)
{
    AbstractDrawable::move(offsetX, offsetY);
}

void arcade::sdl::SDLRectangle::rotate(float angle)
{
    AbstractDrawable::rotate(angle);
}

void arcade::sdl::SDLRectangle::scale(const Vector2f &factor)
{
    AbstractDrawable::scale(factor);
}

void arcade::sdl::SDLRectangle::scale(float factorX, float factorY)
{
    AbstractDrawable::scale(factorX, factorY);
}

void arcade::sdl::SDLRectangle::setSize(const Vector2f &size)
{
    AbstractDrawable::setSize(size);
}

void arcade::sdl::SDLRectangle::update(
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
        throw api::ex::DrawableException("SFMLRectangle::update(): " +  std::string(e.what()));
    }
}

void arcade::sdl::SDLRectangle::setFillColor(
    const arcade::api::renderer::Color &color)
{
    Rectangle::setFillColor(color);
}

void arcade::sdl::SDLRectangle::setBorderColor(
    const arcade::api::renderer::Color &color)
{
    Rectangle::setBorderColor(color);
}

void arcade::sdl::SDLRectangle::draw(SDL_Window *window, SDL_Renderer *render)
{
    (void)window;
    SDL_Rect rect = {(int)this->getPosition().x, (int)this->getPosition().y, (int)this->getSize().x, (int)this->getSize().y};
    if (isFilled()) {
        SDL_SetRenderDrawColor(render, this->getFillColor().getRed(), this->getFillColor().getGreen(), this->getFillColor().getBlue(), this->getFillColor().getAlpha());
        SDL_RenderFillRect(render, &rect);
    }
    SDL_SetRenderDrawColor(render, this->getBorderColor().getRed(), this->getBorderColor().getGreen(), this->getBorderColor().getBlue(), this->getBorderColor().getAlpha());
    SDL_RenderDrawRect(render, &rect);
}
