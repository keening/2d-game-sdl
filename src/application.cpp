#include "../include/application.hpp"
#include "../include/sprite.hpp"

Application::Application() : m_is_running (true)
{
    main_loop();
}

Application::~Application() {}

void Application::main_loop()
{
    SDL_Rect rect = { .x = 932, .y = 2432, .w = 32, .h = 32};
    Sprite test(m_display, "./assets/tileset.png", &rect);
    while (m_is_running) 
    {
        handle_input();
        m_display.clear();
        SDL_Rect r = {.x = 128, .y = 128, .w = 32, .h = 32};
        test.draw(m_display, &r);
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
    }
    else if (current_keystate[SDL_SCANCODE_DOWN])
    {
    }
    else if (current_keystate[SDL_SCANCODE_LEFT])
    {
    }
    else if (current_keystate[SDL_SCANCODE_RIGHT])
    {
    }
    else if (current_keystate[SDL_SCANCODE_ESCAPE])
    {
        m_is_running = false;
    }
}