#pragma once

#include "../include/types.hpp"
#include "../include/sprite.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Display {
    public:
        Display();
        ~Display();

        void clear();
        void render();
        SDL_Renderer *get_renderer();
        SDL_Surface *load_image(const char *texture_path);

    private:
        bool initialize();
        bool initialize_image_support();

        i32 m_win_width = 640, m_win_height = 480;
        SDL_Window *m_window = NULL;
        SDL_Renderer *m_renderer = NULL;
};