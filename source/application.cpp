#include "../include/application.hpp"
#include "../include/sprite.hpp"
#include "../include/player.hpp"

Application::Application() : m_is_running (true)
{
    main_loop();
}

Application::~Application() {}

void Application::main_loop() 
{
    Sprite atlas(m_display, "./assets/tileset.png");
    Player player(m_display, atlas, 0, 0, 20, 20);

    while (m_is_running) 
    {
        handle_input(player);
        m_display.clear();
        player.draw(m_display, atlas);
        m_display.render();
    }
}

void Application::handle_input(Player &player)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            m_is_running = false;
        }
        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_LEFT:
                    player.move(LEFT);
                    break;

                case SDLK_RIGHT:
                    player.move(RIGHT);
                    break;

                case SDLK_UP:
                    player.move(UP);
                    break;

                case SDLK_DOWN:
                    player.move(DOWN);
                    break;

                default:
                    break;
            }
        }
    }
}