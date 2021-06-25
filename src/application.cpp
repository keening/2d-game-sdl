#include "../include/application.hpp"

Application::Application() : m_is_running (true)
{
    main_loop();
}

Application::~Application() {}

void Application::main_loop()
{
    m_player = Player(m_display, 128, 128);

    while (m_is_running) 
    {
        handle_input();
        m_display.clear();
        m_player.draw(m_display);
        m_display.render();
    }
}

void Application::handle_input()
{
    SDL_Event event;
    const auto *current_keystate = SDL_GetKeyboardState(NULL);

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            m_is_running = false;
        }
    }

    if (current_keystate[SDL_SCANCODE_UP])
    {
        m_player.move(UP);
    }
    else if (current_keystate[SDL_SCANCODE_DOWN])
    {
        m_player.move(DOWN);
    }
    else if (current_keystate[SDL_SCANCODE_LEFT])
    {
        m_player.move(LEFT);
    }
    else if (current_keystate[SDL_SCANCODE_RIGHT])
    {
        m_player.move(RIGHT);
    }
    else if (current_keystate[SDL_SCANCODE_ESCAPE])
    {
        m_is_running = false;
    }
}