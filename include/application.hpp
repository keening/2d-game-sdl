#pragma once
#include "../include/display.hpp"

class Player;

class Application {
    public:
        Application();
        ~Application();

    private:
        void main_loop();
        void handle_input();

        bool m_is_running = false;
        Display m_display;
};