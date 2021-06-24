#include "../include/display.hpp"

Display::Display() 
{
    if (!initialize() || !initialize_image_support()) exit(1);
}

Display::~Display() {}

bool Display::initialize()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) 
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    } 
    else 
    {
        m_window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                    m_win_width, m_win_height, SDL_WINDOW_RESIZABLE);

        if (m_window == NULL) 
        {
            SDL_Log("Failed to create SDL Window: %s", SDL_GetError());
            return false;
        } 
        else 
        {
            m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

            if (m_renderer == NULL) 
            {
                SDL_Log("Failed to create SDL Renderer: %s", SDL_GetError());
                return false;
            }
        }
    }
    return true;
}

bool Display::initialize_image_support() 
{
    auto flags = IMG_INIT_JPG | IMG_INIT_PNG;
    auto init_result = IMG_Init(flags);

    if ((init_result&flags) != flags)
    {
        printf("Failed to initialize image library: %s", IMG_GetError());
        return false;
    }
    return true;
}

void Display::clear() const
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(m_renderer);
}

void Display::render() const
{
    SDL_RenderPresent(m_renderer);
}

SDL_Renderer *Display::get_renderer() const
{
    return m_renderer;
}

SDL_Surface *Display::load_image(const char *texture_path)
{
    SDL_Surface *surface = NULL;

    surface = IMG_Load(texture_path);

    if (surface == NULL)
    {
        SDL_Log("Failed to load image %s, error message: %s\n", texture_path, IMG_GetError());
        exit(1);
    }
    return surface;
}

