/*
** EPITECH PROJECT, 2022
** SDLText.cpp
** File description:
** SDLText.cpp
*/

#include "sdl2/SDLText.hpp"

arcade::sdl::SDLText::SDLText(const Text &text) : api::renderer::Text(text.getText(), text.getFontPath(), text.getColor())
{
    _font = TTF_OpenFont(text.getFontPath().c_str(), 24);
    if (_font == nullptr)
        throw api::ex::DrawableException(TTF_GetError());
    SDLText::update(text);
}

arcade::sdl::SDLText::~SDLText()
{
    TTF_CloseFont(_font);
}

void arcade::sdl::SDLText::draw(SDL_Window *window, SDL_Renderer *render)
{
    (void)window;
    SDL_Surface *surface = TTF_RenderText_Solid(_font, this->getText().c_str(), {this->getColor().getRed(), this->getColor().getGreen(), this->getColor().getBlue(), this->getColor().getAlpha()});
    if (surface == nullptr)
        throw api::ex::DrawableException("ezert " + std::string(TTF_GetError()));
    SDL_Texture *texture = SDL_CreateTextureFromSurface(render, surface);
    if (texture == nullptr)
        throw api::ex::DrawableException("akbo " + std::string(TTF_GetError()));
    SDL_FreeSurface(surface);
    SDL_Rect rect = {(int)this->getPosition().x, (int)this->getPosition().y, 0, 0};
    SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
    SDL_SetRenderDrawColor(render, this->getColor().getRed(), this->getColor().getGreen(), this->getColor().getBlue(), this->getColor().getAlpha());
    SDL_RenderCopy(render, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
}

void arcade::sdl::SDLText::setPosition(const Vector2f &pos)
{
    AbstractDrawable::setPosition(pos);
}

void arcade::sdl::SDLText::setPosition(float x, float y)
{
    AbstractDrawable::setPosition(x, y);
}

void arcade::sdl::SDLText::setRotation(float rotation)
{
    AbstractDrawable::setRotation(rotation);
}

void arcade::sdl::SDLText::setScale(const Vector2f &scale)
{
    AbstractDrawable::setScale(scale);
}

void arcade::sdl::SDLText::setScale(float factorX, float factorY)
{
    AbstractDrawable::setScale(factorX, factorY);
}

void arcade::sdl::SDLText::setOrigin(const Vector2f &origin)
{
    AbstractDrawable::setOrigin(origin);
}

void arcade::sdl::SDLText::setOrigin(float x, float y)
{
    AbstractDrawable::setOrigin(x, y);
}

void arcade::sdl::SDLText::move(const Vector2f &offset)
{
    AbstractDrawable::move(offset);
}

void arcade::sdl::SDLText::move(float offsetX, float offsetY)
{
    AbstractDrawable::move(offsetX, offsetY);
}

void arcade::sdl::SDLText::rotate(float angle)
{
    AbstractDrawable::rotate(angle);
}

void arcade::sdl::SDLText::scale(const Vector2f &factor)
{
    AbstractDrawable::scale(factor);
}

void arcade::sdl::SDLText::scale(float factorX, float factorY)
{
    AbstractDrawable::scale(factorX, factorY);
}

void arcade::sdl::SDLText::setSize(const Vector2f &size)
{
    AbstractDrawable::setSize(size);
}

void
arcade::sdl::SDLText::update(const arcade::api::renderer::IDrawable &drawable)
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
        throw api::ex::DrawableException("SDLText::update(): " +  std::string(e.what()));
    }
}

void arcade::sdl::SDLText::setText(const std::string &text)
{
    Text::setText(text);
}

void arcade::sdl::SDLText::setFontPath(const std::string &fontPath)
{
    if (this->getFontPath() == fontPath)
        return;
    Text::setFontPath(fontPath);
    _font = TTF_OpenFont(fontPath.c_str(), 24);
    if (_font == nullptr)
        throw api::ex::DrawableException("azertezert " + std::string(TTF_GetError()));
}

void arcade::sdl::SDLText::setColor(const arcade::api::renderer::Color &color)
{
    Text::setColor(color);
}

void arcade::sdl::SDLText::setHightlighted(bool highlighted)
{
    Text::setHightlighted(highlighted);
}

void arcade::sdl::SDLText::setHighlightColor(
    const arcade::api::renderer::Color &color)
{
    Text::setHighlightColor(color);
}
