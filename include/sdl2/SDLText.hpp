/*
** EPITECH PROJECT, 2022
** SDLText.hpp
** File description:
** SDLText.hpp
*/

#pragma once

#include "api/renderer/Text.hpp"
#include "sdl2/Sdl2.hpp"
#include <SDL2/SDL_ttf.h>

namespace arcade::sdl {
    class SDLText : public api::renderer::Text {

    public:
        explicit SDLText(const Text &);

        ~SDLText() override;

        void draw(SDL_Window *window, SDL_Renderer *render);

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

        void setText(const std::string &text) override;

        void setFontPath(const std::string &fontPath) override;

        void setColor(const api::renderer::Color &color) override;

        void setHightlighted(bool highlighted) override;

        void setHighlightColor(const api::renderer::Color &color) override;

    private:
        TTF_Font *_font;
    };
}