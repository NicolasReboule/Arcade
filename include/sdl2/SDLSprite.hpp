/*
** EPITECH PROJECT, 2022
** SDLSprite.hpp
** File description:
** SDLSprite.hpp
*/

#pragma once

#include "api/renderer/Sprite.hpp"
#include "sdl2/Sdl2.hpp"

namespace arcade::sdl {
    class SDLSprite : public api::renderer::Sprite {
    public:
        SDLSprite(const Sprite &);

        void draw(SDL_Window *, SDL_Renderer *);

        void setPosition(const Vector2f &pos) override;

        void setPosition(float x, float y) override;

        void setRotation(float rotation) override;

        void setScale(const Vector2f &scale) override;

        void setScale(float factorX, float factorY) override;

        void setOrigin(const Vector2f &origin) override;

        void setOrigin(float x, float y) override;

        void move(const Vector2f &offset) override;

        void move(float offsetX, float offsetY) override;

        void rotate(float angle) override;

        void scale(const Vector2f &factor) override;

        void scale(float factorX, float factorY) override;

        void setSize(const Vector2f &size) override;

        void update(const IDrawable &drawable) override;

        void setColor(const api::renderer::Color &color) override;

        void setTexturePath(const std::string &texturePath) override;

    private:
        SDL_Surface *_surface;
        SDL_RendererFlip _flip;
    };
}