#include "../include/sprite.hpp"
#include "../include/display.hpp"

Sprite::Sprite() {}

Sprite::Sprite(Display &display, const char *texture_path, SDL_Rect *source)
{

    SDL_Surface *surface = display.load_image(texture_path);

    m_texture = SDL_CreateTextureFromSurface(display.get_renderer(), surface);

    if (source == NULL) 
    {
        m_src_rect = NULL;
    }
    else 
    {
        m_src_rect = source;
    }
}

Sprite::~Sprite() {}

void Sprite::draw(Display &display, SDL_Rect *destination)
{
    SDL_RenderCopy(display.get_renderer(), m_texture, m_src_rect, destination);
}

void Sprite::clip(SDL_Rect *source)
{
    m_src_rect = source;
}
