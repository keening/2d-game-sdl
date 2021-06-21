#pragma once

#include "../include/types.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SPRITE_SCALE 2

class Display;

class Sprite {
    public:
        Sprite();
        Sprite(Display &display, const char *texture_path);
        ~Sprite();

        SDL_Texture *get_texture();
        void draw_from_atlas(Display &display, i32 src_x, i32 src_y, i32 src_w, i32 src_h, i32 x, i32 y);
        void draw(Display &display, i32 x, i32 y, i32 w, i32 h);

    private:
        SDL_Texture *m_texture = NULL;
};