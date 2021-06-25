#pragma once 

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <SDL2/SDL.h>
#include "../include/types.hpp"

#define SPRITE_SIZE 32

class Display;

class Sprite {
    public:
        Sprite();
        Sprite(Display &display, const char *texture_path, i32 src_x, i32 src_y, i32 x, i32 y);
        ~Sprite();

        virtual void draw(Display &display, i32 x, i32 y);
        SDL_Rect *get_rect();
        void set_rect(vec2_t coords);
        vec2_t read_sprite_from_file(const char *file_path, const char *sprite_name);
        
    private:
        SDL_Rect m_src_rect;
        SDL_Texture *m_texture;
};