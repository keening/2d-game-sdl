#pragma once 

#include "../include/types.hpp"

class Display;
struct SDL_Texture;
struct SDL_Rect;

class Sprite {
    public:
        Sprite();
        Sprite(Display &display, const char *texture_path, SDL_Rect *source);
        ~Sprite();

        virtual void draw(Display &display, SDL_Rect *destination);
        virtual void clip(SDL_Rect *source);
        
    protected:
        SDL_Rect *m_src_rect;
        SDL_Texture *m_texture;
};