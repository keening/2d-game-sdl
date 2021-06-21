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
    Player player(m_display, atlas, 240, 200, 20, 20);

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

        switch (event.key.keysym.sym)
        {
            case SDLK_LEFT:
                player.move(LEFT, 2);
                break;

            case SDLK_RIGHT:
                player.move(RIGHT, 2);
                break;

            case SDLK_UP:
                player.move(UP, 2);
                break;

            case SDLK_DOWN:
                player.move(DOWN, 2);
                break;

            default:
                break;
        }
    }
}