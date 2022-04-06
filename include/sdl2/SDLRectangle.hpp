/*
** EPITECH PROJECT, 2022
** SDLRectangle.hpp
** File description:
** SDLRectangle.hpp
*/

#pragma once

#include "api/renderer/Rectangle.hpp"
#include "sdl2/Sdl2.hpp"

namespace arcade::sdl {
    class SDLRectangle : public api::renderer::Rectangle {

    public:
        SDLRectangle(const Rectangle &);

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

        void setFillColor(const api::renderer::Color &color) override;

        void setBorderColor(const api::renderer::Color &color) override;

        void draw(SDL_Window *window, SDL_Renderer *render);
    };
}