#pragma once
#include "../include/display.hpp"
#include "../include/player.hpp"

class Application {
    public:
        Application();
        ~Application();

    private:
        void main_loop();
        void handle_input();

        bool m_is_running = false;
        Player m_player;
        Display m_display;
};