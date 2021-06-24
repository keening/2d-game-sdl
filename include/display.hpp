#pragma once

#include "../include/types.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Display {
    public:
        Display();
        ~Display();

        void clear() const;
        void render() const;
        SDL_Renderer *get_renderer() const;
        SDL_Surface *load_image(const char *texture_path);

    private:
        bool initialize();
        bool initialize_image_support();

        i32 m_win_width = 1280, m_win_height = 720;
        SDL_Window *m_window = NULL;
        SDL_Renderer *m_renderer = NULL;
};