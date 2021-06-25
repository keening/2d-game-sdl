#include "../include/sprite.hpp"
#include "../include/display.hpp"

Sprite::Sprite() {}

Sprite::Sprite(Display &display, const char *texture_path, 
        i32 src_x, i32 src_y, i32 x, i32 y)
{
    m_src_rect.x = src_x;
    m_src_rect.y = src_y;
    m_src_rect.w = SPRITE_SIZE;
    m_src_rect.h = SPRITE_SIZE;

    SDL_Surface *surface = display.load_image(texture_path);

    m_texture = SDL_CreateTextureFromSurface(display.get_renderer(), surface);

    if (m_texture == NULL)
    {
        printf("Failed to assign texture from surface.\n");
        exit(1);
    }
}

Sprite::~Sprite() {}

void Sprite::draw(Display &display, i32 x, i32 y)
{
    SDL_Rect dest = { x, y, SPRITE_SIZE, SPRITE_SIZE };
    SDL_RenderCopy(display.get_renderer(), m_texture, &m_src_rect, &dest);
}

SDL_Rect *Sprite::get_rect()
{
    return &m_src_rect;
}

void Sprite::set_rect(vec2_t coords)
{
    m_src_rect = { .x = coords.x , .y = coords.y, .w = SPRITE_SIZE, .h = SPRITE_SIZE};
}

vec2_t Sprite::read_sprite_from_file(const char *file_path, const char *sprite_name)
{   
    vec2_t sprite_position = {0, 0};
    std::string buffer;

    std::ifstream file;
    std::string line;

    file.open(file_path);
    while (std::getline(file, line))
    {
        if (line.find(sprite_name) != std::string::npos)
        {
            for (std::string::size_type i = 0; i <= line.size(); i++)
            {
                if (isspace(line[i]) && !buffer.empty())
                {
                    sprite_position.x = std::stoi(buffer);
                    buffer.clear();
                    continue;
                }
                else if (i == line.size())
                {
                    sprite_position.y = std::stoi(buffer);
                }
                else if (isdigit(line[i]))
                {
                    buffer += line[i];
                }
            }
        }
    }
    return sprite_position;
}