/*
** EPITECH PROJECT, 2022
** SDLSprite.cpp
** File description:
** SDLSprite.cpp
*/

#include "sdl2/SDLSprite.hpp"
#include <SDL2/SDL_image.h>

arcade::sdl::SDLSprite::SDLSprite(const Sprite &sprite) : api::renderer::Sprite(sprite.getTexturePath(), sprite.getSymbol())
{
    _surface = IMG_Load(sprite.getTexturePath().c_str());
    if (_surface == nullptr)
        throw api::ex::DrawableException(IMG_GetError());
    SDLSprite::update(sprite);
}

void arcade::sdl::SDLSprite::setPosition(const Vector2f &pos)
{
    AbstractDrawable::setPosition(pos);
}

void arcade::sdl::SDLSprite::setPosition(float x, float y)
{
    AbstractDrawable::setPosition(x, y);
}

void arcade::sdl::SDLSprite::setRotation(float rotation)
{
    AbstractDrawable::setRotation(rotation);
    _angle = rotation;
}

void arcade::sdl::SDLSprite::setScale(const Vector2f &scale)
{
    AbstractDrawable::setScale(scale);
}

void arcade::sdl::SDLSprite::setScale(float factorX, float factorY)
{
    AbstractDrawable::setScale(factorX, factorY);
}

void arcade::sdl::SDLSprite::setOrigin(const Vector2f &origin)
{
    AbstractDrawable::setOrigin(origin);
}

void arcade::sdl::SDLSprite::setOrigin(float x, float y)
{
    AbstractDrawable::setOrigin(x, y);
}

void arcade::sdl::SDLSprite::move(const Vector2f &offset)
{
    AbstractDrawable::move(offset);
}

void arcade::sdl::SDLSprite::move(float offsetX, float offsetY)
{
    AbstractDrawable::move(offsetX, offsetY);
}

void arcade::sdl::SDLSprite::rotate(float angle)
{
    AbstractDrawable::rotate(angle);
}

void arcade::sdl::SDLSprite::scale(const Vector2f &factor)
{
    AbstractDrawable::scale(factor);
}

void arcade::sdl::SDLSprite::scale(float factorX, float factorY)
{
    AbstractDrawable::scale(factorX, factorY);
}

void arcade::sdl::SDLSprite::setSize(const Vector2f &size)
{
    AbstractDrawable::setSize(size);
}

void
arcade::sdl::SDLSprite::update(const arcade::api::renderer::IDrawable &drawable)
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
        this->setFlipType(sprite.getFlipType());
    } catch (std::bad_cast &e) {
        throw api::ex::DrawableException("SDLSprite::update(): " +  std::string(e.what()));
    }}

void arcade::sdl::SDLSprite::setColor(const arcade::api::renderer::Color &color)
{
    Sprite::setColor(color);
}

void arcade::sdl::SDLSprite::setTexturePath(const std::string &texturePath)
{
    if (texturePath == this->getTexturePath())
        return;
    SDL_FreeSurface(_surface);
    _surface = IMG_Load(texturePath.c_str());
    if (_surface == nullptr)
        throw api::ex::DrawableException(IMG_GetError());
    Sprite::setTexturePath(texturePath);
}

void arcade::sdl::SDLSprite::draw(SDL_Window *window, SDL_Renderer *render)
{
    (void)window;
    auto texture = SDL_CreateTextureFromSurface(render, _surface);
    SDL_Rect rect = {(int)this->getPosition().x, (int)this->getPosition().y, 0, 0};
    SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
    SDL_SetRenderDrawColor(render, this->getColor().getRed(), this->getColor().getGreen(), this->getColor().getBlue(), this->getColor().getAlpha());
    SDL_RenderCopyEx(render, texture, nullptr, &rect, this->_angle, nullptr, this->_flip);
    SDL_DestroyTexture(texture);
}

void arcade::sdl::SDLSprite::setFlipType(const FlipType &flipType)
{
    Sprite::setFlipType(flipType);
    switch (flipType) {
        case NONE:
            _flip = SDL_FLIP_NONE;
            break;
        case HORIZONTAL:
            _flip = SDL_FLIP_HORIZONTAL;
            break;
        case VERTICAL:
            _flip = SDL_FLIP_VERTICAL;
            break;
    }
}
