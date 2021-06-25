#pragma once 

#include "../include/sprite.hpp"

class Display;

class Player : Sprite {
    public:
        Player();
        Player(Display &display, i32 x, i32 y);
        ~Player();

        void draw(Display &display);
        void move(Direction dir);
        void set_sprite(Display &display);

    private:
        i32 m_x = 0, m_y = 0, m_w = 0, m_h = 0;
        i32 m_speed = 32; 
        vec2_t sprite_coords = { 0, 0 };
        bool done_already = false;
};