#include "../include/sprite.hpp"
#include "../include/display.hpp"

Sprite::Sprite() {}

Sprite::Sprite(Display &display, const char *texture_path)
{
    m_texture = SDL_CreateTextureFromSurface(display.get_renderer(), display.load_image(texture_path));

    if (m_texture == NULL) 
    {
        SDL_Log("Failed to create texture %s, error message: %s\n", texture_path, SDL_GetError());
    }
}

Sprite::~Sprite() {}

SDL_Texture *Sprite::get_texture()
{
    return m_texture;
}

void Sprite::draw_from_atlas(Display &display, i32 x, i32 y, i32 w, i32 h, i32 src_x, i32 src_y)
{
    SDL_Rect src = { src_x, src_y, w, h}, dest = { x, y, w * SPRITE_SCALE, h * SPRITE_SCALE};

    SDL_RenderCopy(display.get_renderer(), m_texture, &src, &dest);
}

void Sprite::draw(Display &display, i32 x, i32 y, i32 w, i32 h)
{
    SDL_Rect dest = { x, y, w, h };

    SDL_RenderCopy(display.get_renderer(), m_texture, NULL, &dest);
}

